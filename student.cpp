#include "student.h" 
#include <iomanip>   


void addStudent(map<int, pair<string, vector<pair<double, double>>>>& students) 
{
    int id;
    string name;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); 
    cout << "Enter student name: ";
    getline(cin, name);

    vector<pair<double, double>> grades; 

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') 
    {
        double credits, gradePoints;

        cout << "Enter credits for the course: ";
        cin >> credits;
        cout << "Enter grade points for the course: ";
        cin >> gradePoints;

        grades.push_back(make_pair(credits, gradePoints)); 

        cout << "Do you want to add another course? (y/n): ";
        cin >> choice;
    }

    students[id] = make_pair(name, grades); 
    cout << "Student added successfully!" << endl;
}


double calculateGPA(const vector<pair<double, double>>& grades) 
{
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (const auto& course : grades) 
    {
        double credits = course.first;
        double gradePoints = course.second;

        totalCredits += credits;
        totalGradePoints += (credits * gradePoints);
    }

    if (totalCredits == 0) 
    {
        return 0.0; 
    }

    return totalGradePoints / totalCredits;
}


double calculateAverageGPA(const map<int, pair<string, vector<pair<double, double>>>>& students) 
{
    double totalGPA = 0.0;
    int studentCount = 0;

    for (const auto& student : students) 
    {
        const vector<pair<double, double>>& grades = student.second.second;
        double gpa = calculateGPA(grades);
        totalGPA += gpa;
        studentCount++;
    }

    if (studentCount == 0) 
    {
        return 0.0; 
    }

    return totalGPA / studentCount;
}