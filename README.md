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

------------------------------------------------------------------------

## ** How to Run the Project**

### **1. Install GCC (if needed)**

#### **Windows:**

Use *MinGW* or *TDM-GCC*

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
