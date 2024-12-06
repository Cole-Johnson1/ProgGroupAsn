// Author: Cole Johnson
// Date: Dec 6th 2024
#include "file_io.h"

void saveAppointmentsToFile(Appointment* appts, int count) {
    FILE* file = fopen(FILENAME, "wb");
    fwrite(&count, sizeof(int), 1, file);
    fwrite(appts, sizeof(Appointment), count, file);
    fclose(file);
    printf("Appointments saved successfully!\n");
}

void loadAppointmentsFromFile(Appointment** appts, int* count) {
    FILE* file = fopen(FILENAME, "rb");
    if (file) {
        fread(count, sizeof(int), 1, file);
        *appts = realloc(*appts, (*count) * sizeof(Appointment));
        fread(*appts, sizeof(Appointment), *count, file);
        fclose(file);
        printf("Appointments loaded successfully!\n");
    }
    else {
        printf("No existing file found.\n");
    }
}
