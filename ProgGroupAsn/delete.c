// Author: Cole Johnson
// Date: Dec 6th 2024

#include "delete.h"

void deleteAppointment(Appointment** appts, int* count, int id) {
    for (int i = 0; i < *count; i++) {
        if ((*appts)[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                (*appts)[j] = (*appts)[j + 1];
            }
            (*count)--;
            Appointment* temp = realloc(*appts, (*count) * sizeof(Appointment));
            if (!temp && *count > 0) {
                printf("Memory allocation failed. Data integrity preserved.\n");
                return;
            }
            *appts = temp;
            printf("Appointment deleted successfully!\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}
