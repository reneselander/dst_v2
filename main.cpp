#include "calculations.h"

#include <iostream>

#include <limits>

#include <string>

#include <sstream>

#include <algorithm> // Include this header for std::replace

#include <iomanip>   // Include this header for std::fixed and std::setprecision RS74

void clearInput() {

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

double getValidatedInput(const std::string& prompt) {

    std::string input;

    double value;

    while (true) {

        std::cout << prompt;

        std::cin >> input;

        std::replace(input.begin(), input.end(), ',', '.');

        std::stringstream ss(input);

        if (ss >> value && value > 0) {

            return value;

        } else {

            std::cout << "Invalid input. Please enter a positive number.\n\n";

            clearInput();

        }

    }

}

double getTimeInput() {

    int hours, minutes;

    while (true) {

        std::cout << "Enter time (hours and minutes, separated by space): ";

        std::cin >> hours >> minutes;

        if (std::cin.fail() || hours < 0 || minutes < 0 || minutes >= 60) {

            std::cout << "Invalid input. Please enter valid hours and minutes.\n\n";

            clearInput();

        } else {

            return hours + minutes / 60.0;

        }

    }

}

void displayTime(double time) {

    int hours = static_cast<int>(time);

    int minutes = static_cast<int>((time - hours) * 60);

    std::cout << "\nTime: " << hours << " hours and " << minutes << " minutes\n\n";

}

int main() {

    double speed, distance, time;

    int choice;

    while (true) {

        std::cout << "* * * Choose the calculation you want to perform: * * *\n\n";

        std::cout << "1. Calculate required speed (knots)\n\n";

        std::cout << "2. Calculate distance (nautical miles)\n\n";

        std::cout << "3. Calculate time (hours and minutes)\n\n";

        std::cout << "4. Exit\n\n";

        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 4) {

            std::cout << "Invalid choice. Enter a number between 1 and 4.\n";

            clearInput();

            continue;

        }

        if (choice == 4) {

            break;

        }

        switch (choice) {

            case 1:
                distance = getValidatedInput("Enter distance (nautical miles): ");

                time = getTimeInput();

                speed = calculateSpeed(distance, time);

                std::cout << std::fixed << std::setprecision(2);

                std::cout << "\nSpeed: " << speed << " knots\n\n";

                break;

                case 2:

                speed = getValidatedInput("Enter speed (knots): ");

                time = getTimeInput();

                distance = calculateDistance(speed, time);

                std::cout << std::fixed << std::setprecision(2);

                std::cout << "\nDistance: " << distance << " nautical miles\n\n";

                break;

                case 3:

                distance = getValidatedInput("Enter distance (nautical miles): ");

                speed = getValidatedInput("\nEnter speed (knots): ");

                time = calculateTime(distance, speed);

                displayTime(time);

                break;

            }

        }

        
    return 0;
}
