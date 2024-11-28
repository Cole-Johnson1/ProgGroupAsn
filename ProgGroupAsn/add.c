#define _CRT_SECURE_NO_WARNINGS
// add.c
// Author: [Your Name]
// Date: [Insert Date]
// Description: Implements the add appointment functionality.

#include "add.h"

void addAppointment(Appointment** appts, int* count) {
    Appointment* temp = realloc(*appts, (*count + 1) * sizeof(Appointment));
    if (!temp) {
        printf("Memory allocation failed.\n");
        return;
    }
    *appts = temp;
    char input[20];
    struct tm tm = { 0 };
    Appointment* newAppt = &(*appts)[*count];
    newAppt->id = *count + 1; // Assign ID

    printf("Enter title: ");
    scanf(" %[^\n]s", newAppt->title);
    printf("Enter description: ");
    scanf(" %[^\n]s", newAppt->description);

    printf("Enter date and time (YYYY-MM-DD HH:MM): ");
    scanf(" %[^\n]s", input);
    sscanf(input, "%d-%d-%d %d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    newAppt->datetime = mktime(&tm);

    (*count)++;
    printf("Appointment added successfully! Assigned ID: %d\n", newAppt->id); // Show ID
}

