#pragma once
#ifndef FEATURES_H
#define FEATURES_H

#include <string>
#include <ctime> // For time_t

// Structure to represent an appointment
struct Appointment {
    int id; // Unique identifier for the appointment
    std::string title; // Title of the appointment
    std::string date; // Date of the appointment
    std::string time; // Time of the appointment
    std::string description; // Description of the appointment
    time_t datetime; // Date and time as a single value
};

// Function declarations
bool addAppointment(Appointment& appointment);
bool updateAppointment(Appointment& appointment);
bool deleteAppointment(Appointment* appts, int& count, int id);
std::string displayAppointment(const Appointment& appointment);

#endif // FEATURES_H