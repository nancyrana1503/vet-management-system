#ifndef CLINIC_H
#define CLINIC_H

#define FMT_FORM 1
#define FMT_TABLE 2

#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

#define MINUTE_INTERVAL 30
#define START_HOUR 10
#define END_HOUR 14

struct Phone {
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};

struct Patient {
    int patientNumber;
    char name[NAME_LEN];
    struct Phone phone;
};

struct Time {
    int hour, min;
};

struct Date {
    int day, year, month;
};

struct Appointment {
    int patientNumber;
    struct Date date;
    struct Time time;
};

struct ClinicData {
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};

// Display Functions
void displayPatientTableHeader(void);
void displayPatientData(const struct Patient* patient, int fmt);
void displayScheduleTableHeader(const struct Date* date, int isAllRecords);
void displayScheduleData(const struct Patient* patient, const struct Appointment* appoint, int includeDateField);

// Menu & Item Selection Functions
void menuMain(struct ClinicData* data);
void menuPatient(struct Patient patient[], int max);
void menuPatientEdit(struct Patient* patient);
void menuAppointment(struct ClinicData* data);
void displayAllPatients(const struct Patient patient[], int max, int fmt);
void searchPatientData(const struct Patient patient[], int max);
void addPatient(struct Patient patient[], int max);
void editPatient(struct Patient patient[], int max);
void removePatient(struct Patient patient[], int max);
void viewAllAppointments(struct ClinicData* data);
void viewAppointmentSchedule(struct ClinicData* data);
void addAppointment(struct Appointment* app, int, struct Patient* pt, int);
void removeAppointment(struct Appointment* app, int, struct Patient* pt, int);

// Utility Functions
void searchPatientByPatientNumber(const struct Patient patient[], int max);
void searchPatientByPhoneNumber(const struct Patient patient[], int max);
int nextPatientNumber(const struct Patient patient[], int max);
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max);
int timeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments);
int nextSlotAvailable(struct Appointment* app, int maxAppointments);
int validAppointment(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments);

// User Input Functions
void inputPatient(struct Patient* patient);
void inputPhoneData(struct Phone* phone);

// File Functions
int importPatients(const char* datafile, struct Patient patients[], int max);
int importAppointments(const char* datafile, struct Appointment appoints[], int max);

#endif
