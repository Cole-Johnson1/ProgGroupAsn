#ifndef FILE_IO_H
#define FILE_IO_H

#include "appointment.h"

void saveAppointmentsToFile(Appointment* appts, int count);
void loadAppointmentsFromFile(Appointment** appts, int* count);

#endif // FILE_IO_H
