#define _CRT_SECURE_NO_WARNINGS
// update.c
// Author: [Your Name]
// Date: [Insert Date]
// Description: Implements the update appointment functionality.

#include "update.h"

void updateAppointment(Appointment* appts, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (appts[i].id == id) {
            char input[20];
            struct tm tm = { 0 };
            printf("Enter new title: ");
            scanf(" %[^\n]s", appts[i].title);
            printf("Enter new description: ");
            scanf(" %[^\n]s", appts[i].description);

            printf("Enter new date and time (YYYY-MM-DD HH:MM): ");
            scanf(" %[^\n]s", input);
            scanf(input, "%d-%d-%d %d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
            tm.tm_year -= 1900;
            tm.tm_mon -= 1;
            appts[i].datetime = mktime(&tm);

            printf("Appointment updated successfully!\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}
