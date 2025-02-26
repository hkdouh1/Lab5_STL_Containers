#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


void addStudent(map<int, pair<string, vector<pair<double, double>>>>& students);

double calculateGPA(const vector<pair<double, double>>& grades);

double calculateAverageGPA(const map<int, pair<string, vector<pair<double, double>>>>& students);

#endif