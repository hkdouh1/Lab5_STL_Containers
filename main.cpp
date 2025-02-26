#include "student.h" 
#include <iostream>
#include <iomanip>   
using namespace std;

int main() 
{
    map<int, pair<string, vector<pair<double, double>>>> students; 
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new student\n";
        cout << "2. Calculate GPA for a single student\n";
        cout << "3. Calculate average GPA of all students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            addStudent(students);
            break;
        }
        case 2: 
        {
            int id;

            cout << "Enter the student ID to calculate GPA: ";
            cin >> id;

            if (students.find(id) != students.end()) 
            {
                const vector<pair<double, double>>& grades = students[id].second;
                double gpa = calculateGPA(grades);

                cout << "GPA for student " << students[id].first << " is: " << fixed << setprecision(2) << gpa << endl;
            }
            else 
            {
                cout << "Student with ID " << id << " not found!" << endl;
            }
            break;
        }
        case 3: 
        {
            double avgGPA = calculateAverageGPA(students);

            cout << "Average GPA of all students is: " << fixed << setprecision(2) << avgGPA << endl;
            break;
        }
        case 4: 
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        default: 
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}