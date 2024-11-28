// appointment.h
// Author: [Your Name]
// Date: [Insert Date]
// Description: Shared definitions for the Appointment Manager.

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define FILENAME "appointments.dat"

// Appointment structure
typedef struct {
    int id;
    char title[50];
    char description[200];
    time_t datetime; // UNIX timestamp
} Appointment;

#endif // APPOINTMENT_H
