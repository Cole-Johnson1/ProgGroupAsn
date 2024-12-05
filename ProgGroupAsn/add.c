//keno - prog71990- Group asssignment

#define _CRT_SECURE_NO_WARNINGS

#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addAppointment(Appointment** appts, int* count) {
    Appointment* temp = malloc((*count + 1) * sizeof(Appointment));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Copy existing appointments to the new array
    for (int i = 0; i < *count; i++) {
        temp[i] = (*appts)[i];
    }
    free(*appts);
    *appts = temp;

    Appointment* newAppt = &(*appts)[*count];
    newAppt->id = *count + 1; // Assign ID

    printf("Enter title: ");
    if (scanf(" %[^\n]s", newAppt->title) != 1) {
        fprintf(stderr, "Failed to read title.\n");
        return;
    }

    printf("Enter description: ");
    if (scanf(" %[^\n]s", newAppt->description) != 1) {
        fprintf(stderr, "Failed to read description.\n");
        return;
    }

    char input[20] = { 0 };
    struct tm tm = { 0 };

    printf("Enter date and time (YYYY-MM-DD HH:MM): ");
    if (scanf(" %[^\n]s", input) != 1) {
        fprintf(stderr, "Failed to read date and time.\n");
        return;
    }

    if (sscanf(input, "%d-%d-%d %d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min) != 5) {
        fprintf(stderr, "Invalid date and time format.\n");
        return;
    }

    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    newAppt->datetime = mktime(&tm);

    (*count)++;
    printf("Appointment added successfully! Assigned ID: %d\n", newAppt->id); // Show ID
}