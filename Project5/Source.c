/*
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_APPOINTMENTS 100
#define DAYS_IN_MONTH 31
#define TIME_SLOTS_PER_DAY 24

int numAppointments = 0;
int appointments[MAX_APPOINTMENTS];
int appointmentCalendar[DAYS_IN_MONTH][TIME_SLOTS_PER_DAY];

void displayCalendar(int, int, int, int);
void bookAppointment()
{
    FILE* fp = fopen("appointments.csv", "a + ");
    FILE* fp1 = fopen("dr_aps.csv", "a+");
    FILE* fp2 = fopen("dr_aps.csv", "a+");
    FILE* fp3 = fopen("dr_aps.csv", "a+");

    char patient[10];
    int time, date, ch;

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: No available appointments\n");
        return;
    }

    printf("Enter patient name: ");
    scanf("%s", patient);

    printf("Choose Doctor: \n");
    printf("1.Dr ABC\n2.Dr XYZ\n3.Dr AAA\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("View Calender to check available slots:");
        getch();
        displayCalendar(1, 10, 10, 15);
        label1a:
        printf("Enter appointment date (1-10): ");
        scanf("%d", &date);
        if (date <= 10 && date >= 1)
            ;
        else
            goto label1a;

        label1b:
        printf("Enter appointment time (10-15): ");
        scanf("%d", &time);
        if (date <= 10 && date >= 1)
            ;
        else
            goto label1b;
        char doctor[] = "Dr ABC";
        if (appointmentCalendar[date ][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp1, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient, doctor, date, time);
        break;

    case 2:
        printf("View Calender to check available solts:");
        getch();
        displayCalendar(15, 30, 10, 20);
        printf("Enter appointment date (15-30): ");
        scanf("%d", &date);

        printf("Enter appointment time (10-20): ");
        scanf("%d", &time);
        char doctor1[] = "Dr XYZ";
        if (appointmentCalendar[date][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date ][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp2, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient, doctor1, date, time);
        break;

    case 3:
        printf("View Calender to check available solts:");
        getch();
        displayCalendar(1, 15, 10, 18);
        printf("Enter appointment date (1-15): ");
        scanf("%d", &date);

        printf("Enter appointment time (10-18): ");
        scanf("%d", &time);
        char doctor2[] = "Dr AAA";
        if (appointmentCalendar[date][time] == 1)
        {
            printf("Appointment for this slot is already booked\n");
            printf("Choose another slot\n\n");
            return;
        }
        else
        {
            appointmentCalendar[date][time] = 1;
            numAppointments++;
        }
        printf("Appointment booked successfully\n\n");
        fprintf(fp3, "%s, %d, %d:00\n", patient, date, time);
        fprintf(fp, "%s, %s, %d, %d:00\n", patient, doctor2, date, time);
        break;
    }
    fcloseall();
}


void displayCalendar(int d, int days, int t, int time) {
    printf("Calendar:\n");
    printf("Time/\nDate");
    for (int i = d; i <= days; i++) {
        printf("[%4d]\t", i);
    }
    printf("\n");
    for (int i = t; i <= time; i++) {
        printf("%4d:00\t", i);
        for (int j = d; j <= days; j++) {
            printf("%4d\t", appointmentCalendar[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Book Appointment\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            bookAppointment();
            break;
        case 2:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
*/