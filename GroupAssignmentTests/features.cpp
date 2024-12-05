#include <iostream>
#include <vector>


struct Appointment {
    int id;
    std::string title;
    std::string date;
    std::string time;
    std::string description;
};

void addAppointment(Appointment*, appointment) {
    // Create a dynamic array to hold appointments
    static Appointment* appts = nullptr;
    static int count = 0;

    // Add the new appointment
    addAppointment(&appts, &count);

    // Copy the added appointment to the provided reference
    if (count > 0) {
        appointment = appts[count - 1];
    }
}

bool updateAppointment(Appointment& appointment) {
    // Add logic to update the appointment
    return true; // Return true for successful update
}

bool deleteAppointment(Appointment* appts, int& count, int id) {
    // Find the appointment by id and remove it
    auto end = appts + count;
    auto it = std::remove_if(appts, end, [](const Appointment& appt) {
        return appt.id == id;
        });

    if (it != end) {
        --count;
        return true; // Return true for successful deletion
    }
    return false; // Return false if appointment not found
}

std::string displayAppointment(const Appointment& appointment) {
    return "Title: " + appointment.title + "\nDate: " + appointment.date + "\nTime: " + appointment.time + "\nDescription: " + appointment.description;
}