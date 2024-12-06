// Author: Cole Johnson
// Date: Dec 6th 2024
#define _CRT_SECURE_NO_WARNINGS
#include "display.h"

void displaySingleAppointment(Appointment* appts, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (appts[i].id == id) {
            printf("ID: %d\nTitle: %s\nDescription: %s\nDatetime: %s\n",
                appts[i].id, appts[i].title, appts[i].description, ctime(&appts[i].datetime));
            return;
        }
    }
    printf("Appointment not found.\n");
}

void displayAllAppointments(Appointment* appts, int count) {
    if (count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n=== Appointment %d ===\n", appts[i].id);
        displaySingleAppointment(appts, count, appts[i].id);
    }
}

