# **Appointment Scheduling System (C Program)**

A simple terminal-based Appointment Scheduling System written in C.\
The program lets users schedule, view, edit, and cancel appointments
while ensuring no duplicate bookings occur for the same doctor at the
same time.

------------------------------------------------------------------------

## ** Functional Requirements**

The system must allow the user to:

### **1. Schedule an Appointment**

-   Patient Name\
-   Date (dd/mm/yyyy)\
-   Time (hh:mm, 24-hour format)\
-   Doctor Name\
-   Validate date & time\
-   Prevent double-booking of doctor slots

### **2. View Appointments**

-   Display all scheduled appointments in a numbered list.

### **3. Edit an Appointment**

-   Modify:
    -   Patient name\
    -   Date\
    -   Time\
    -   Doctor name\
-   Option to keep existing values

### **4. Cancel an Appointment**

-   Remove an appointment by selecting its number.

### **5. Exit**

-   Close the application gracefully.

------------------------------------------------------------------------

## ** Features**

-    Menu-driven interface\
-    Date and time validation\
-    Prevention of duplicate doctor schedules\
-    Edit only the fields you want to change\
-    Screen clear support (Windows & Linux)\
-    Handles up to 100 appointments
-    
## MAIN FUNCTION IN LOOPS
- do - while loop
- And for loops for
- 1. appointmentExists():
  2. viewAppointments():
  3. cancelAppointment(): 
------------------------------------------------------------------------

## ** How to Run the Project**

### **1. Install GCC (if needed)**

#### **Windows:**

Use *MinGW* 

``` bash
gcc --version
```

------------------------------------------------------------------------

### **2. Save the Source Code**

Save your C program as:

    appointment_system.c

------------------------------------------------------------------------

### **3. Compile the Program**

Open Terminal / CMD in the folder containing the file:

``` bash
gcc appointment_system.c -o appointment_system
```

------------------------------------------------------------------------

### **4. Run the Program**

#### **Windows**

    appointment_system.exe



``` bash
./appointment_system
```

------------------------------------------------------------------------

## ** Screenshots **

<img width="493" height="253" alt="image" src="https://github.com/user-attachments/assets/29a99e6b-ecf2-4aa7-9e38-49aecc049724" />

<img width="492" height="249" alt="Screenshot 2025-11-21 160650" src="https://github.com/user-attachments/assets/f2874cdd-f176-4568-a5e3-ecfcf55e2b42" />


<img width="770" height="258" alt="Screenshot 2025-11-21 160757" src="https://github.com/user-attachments/assets/6d4c30ef-e3f5-4577-9371-9d3f1ced760a" />


<img width="477" height="262" alt="Screenshot 2025-11-21 160832" src="https://github.com/user-attachments/assets/6aeac4fe-d1f1-4b18-b288-cc1f3dd497b0" />



### **Main Menu**

    --- Appointment Scheduling System ---
    1. Schedule an Appointment
    2. View Appointments
    3. Edit an Appointment
    4. Cancel an Appointment
    0. Exit
    Enter your choice:

### **Sample Appointment Entry**

    1. John Doe with Dr. Smith on 12/05/2025 at 14:30

------------------------------------------------------------------------
