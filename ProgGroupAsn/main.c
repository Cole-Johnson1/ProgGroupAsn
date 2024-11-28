#define _CRT_SECURE_NO_WARNINGS
#include "add.h"
#include "delete.h"
#include "update.h"
#include "display.h"
#include "file_io.h"

int main() {
    Appointment* appointments = NULL;
    int count = 0;
    int choice;
    int id;

    loadAppointmentsFromFile(&appointments, &count);

    while (1) {
        printf("\n=== Appointment Manager ===\n");
        printf("1. Add Appointment\n2. Delete Appointment\n3. Update Appointment\n4. Display Appointment\n5. Display All Appointments\n6. Save to Disk\n7. Load from Disk\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAppointment(&appointments, &count);
            break;
        case 2: // Delete Appointment
            if (count == 0) {
                printf("No appointments to delete.\n");
                break;
            }
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteAppointment(&appointments, &count, id);
            break;

        case 3: // Update Appointment
            if (count == 0) {
                printf("No appointments to update.\n");
                break;
            }
            printf("Enter ID to update: ");
            scanf("%d", &id);
            updateAppointment(appointments, count, id);
            break;

        case 4: // Display Single Appointment
            if (count == 0) {
                printf("No appointments to display.\n");
                break;
            }
            printf("Enter ID to display: ");
            scanf("%d", &id);
            displaySingleAppointment(appointments, count, id);
            break;

        case 5: // Display All Appointments
            displayAllAppointments(appointments, count);
            break;

        case 6:
            saveAppointmentsToFile(appointments, count);
            break;
        case 7:
            loadAppointmentsFromFile(&appointments, &count);
            break;
        case 0:
            saveAppointmentsToFile(appointments, count);
            free(appointments);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
