#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char patient[50];
    int day, month, year;
    int hour, minute;
    char doctor[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;

    if (month == 2) {
        // Leap year check
        int leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (leap && day > 29) return 0;
        if (!leap && day > 28) return 0;
    }
    return 1;
}

int isValidTime(int hour, int minute) {
    return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60);
}

int appointmentExists(int day, int month, int year, int hour, int minute, char doctor[]) {
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].day == day &&
            appointments[i].month == month &&
            appointments[i].year == year &&
            appointments[i].hour == hour &&
            appointments[i].minute == minute &&
            strcmp(appointments[i].doctor, doctor) == 0) {
            return 1;
        }
    }
    return 0;
}

void scheduleAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached.\n");
        return;
    }

    Appointment newApp;

    printf("Enter patient name: ");
    scanf(" %[^\n]", newApp.patient);

    printf("Enter appointment date (dd mm yyyy): ");
    scanf("%d %d %d", &newApp.day, &newApp.month, &newApp.year);

    if (!isValidDate(newApp.day, newApp.month, newApp.year)) {
        printf("Invalid date entered.\n");
        return;
    }

    printf("Enter appointment time (hh mm, 24-hour format): ");
    scanf("%d %d", &newApp.hour, &newApp.minute);

    if (!isValidTime(newApp.hour, newApp.minute)) {
        printf("Invalid time entered.\n");
        return;
    }

    printf("Enter doctor name: ");
    scanf(" %[^\n]", newApp.doctor);

    if (appointmentExists(newApp.day, newApp.month, newApp.year, newApp.hour, newApp.minute, newApp.doctor)) {
        printf("That slot with this doctor is already booked.\n");
        return;
    }

    appointments[appointmentCount++] = newApp;
    printf("Appointment scheduled successfully!\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s with Dr. %s on %02d/%02d/%4d at %02d:%02d\n", i + 1,
            appointments[i].patient, appointments[i].doctor,
            appointments[i].day, appointments[i].month, appointments[i].year,
            appointments[i].hour, appointments[i].minute);
    }
}

void cancelAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to cancel.\n");
        return;
    }

    int idx;
    viewAppointments();
    printf("Enter appointment number to cancel: ");
    scanf("%d", &idx);

    if (idx < 1 || idx > appointmentCount) {
        printf("Invalid appointment number.\n");
        return; 
    }

    for (int i = idx - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment canceled.\n");
}

void editAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to edit.\n");
        return;
    }

    int idx;
    viewAppointments();
    printf("Enter appointment number to edit: ");
    scanf("%d", &idx);

    if (idx < 1 || idx > appointmentCount) {
        printf("Invalid appointment number.\n");
        return;
    }

    Appointment *app = &appointments[idx - 1];

    printf("Editing appointment for %s with Dr. %s\n", app->patient, app->doctor);
    printf("Enter new patient name (leave blank to keep current): ");
    char temp[50];
    getchar(); // to consume leftover newline
    fgets(temp, sizeof(temp), stdin);
    if (temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(app->patient, temp);
    }

    printf("Enter new appointment date (dd mm yyyy), or 0 0 0 to keep current: ");
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    if (!(d == 0 && m == 0 && y == 0)) {
        if (!isValidDate(d, m, y)) {
            printf("Invalid date entered. Edit aborted.\n");
            return;
        }
        app->day = d; app->month = m; app->year = y;
    }

    printf("Enter new appointment time (hh mm), or -1 -1 to keep current: ");
    int h, mm;
    scanf("%d %d", &h, &mm);
    if (!(h == -1 && mm == -1)) {
        if (!isValidTime(h, mm)) {
            printf("Invalid time entered. Edit aborted.\n");
            return;
        }
        app->hour = h; app->minute = mm;
    }

    printf("Enter new doctor name (leave blank to keep current): ");
    getchar();
    fgets(temp, sizeof(temp), stdin);
    if (temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strcpy(app->doctor, temp);
    }

    printf("Appointment updated successfully.\n");
}

void displayMenu() {
    printf("\n--- Appointment Scheduling System ---\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Edit an Appointment\n");
    printf("4. Cancel an Appointment\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: scheduleAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: editAppointment(); break;
            case 4: cancelAppointment(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
