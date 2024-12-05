#include "pch.h"
#include "CppUnitTest.h"
#include "features.h"
#include "add.h"
#include "update.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GroupAssignmentTests
{
    TEST_CLASS(AppointmentTests)
    {
    public:
        // Test for adding an appointment
        TEST_METHOD(TestAddAppointment)
        {
            Appointment appointment = { 1, "Meeting", "2024-12-03", "10:00", "Project discussion", time(nullptr) };
            bool result = addAppointment(appointment);
            Assert::IsTrue(result);
        }

        // Test for updating an appointment
        TEST_METHOD(TestUpdateAppointment)
        {
            Appointment appointments[1] = { {1, "Meeting", "2024-12-03", "10:00", "Project discussion", time(nullptr)} };
            int count = 1;
            int id = 1;

            // Simulate user input for updating the appointment
            freopen("CONIN$", "r", stdin); // Redirect standard input to console
            std::istringstream input("Updated Meeting\nUpdated description\n2024-12-04 11:00\n");
            std::cin.rdbuf(input.rdbuf());

            updateAppointment(appointments, count, id);

            Assert::AreEqual(std::string("Updated Meeting"), std::string(appointments[0].title));
            Assert::AreEqual(std::string("Updated description"), std::string(appointments[0].description));
            // Add more assertions to check the date and time if needed
        }

        // Test for deleting an appointment
        TEST_METHOD(TestDeleteAppointment)
        {
            Appointment appointments[1] = { {1, "Meeting", "2024-12-03", "10:00", "Project discussion", time(nullptr)} };
            int count = 1;
            int id = 1;

            bool deleteResult = deleteAppointment(appointments, count, id);
            Assert::IsTrue(deleteResult);
            Assert::AreEqual(0, count); // Ensure the count is decremented
        }

        // Test for displaying an appointment
        TEST_METHOD(TestDisplayAppointment)
        {
            Appointment appointment = { 1, "Meeting", "2024-12-03", "10:00", "Project discussion", time(nullptr) };
            std::string expectedDisplay = "Title: Meeting\nDate: 2024-12-03\nTime: 10:00\nDescription: Project discussion";
            std::string displayResult = displayAppointment(appointment);
            Assert::AreEqual(expectedDisplay, displayResult);
        }
    };
}