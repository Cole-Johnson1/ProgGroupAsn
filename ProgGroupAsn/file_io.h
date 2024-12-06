// Author: Cole Johnson
// Date: Dec 6th 2024
#ifndef FILE_IO_H
#define FILE_IO_H

#include "appointment.h"

void saveAppointmentsToFile(Appointment* appts, int count);
void loadAppointmentsFromFile(Appointment** appts, int* count);

#endif 