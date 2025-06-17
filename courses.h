#ifndef COURSES_H
#define COURSES_H
#include "scores.h"
#include "gpa_letter_mapping.h"
#include <iomanip>

using namespace std;

class Courses {
private:
    string name;
    int credits;
    double gpa;
    double current_score;
    double expected;
    vector<Items> items;
public:
    Courses(string n = "null", int c = 0, double g = 0, double e = 60, vector<Items> init = {});
    double calculate_score();
    double get_weighted_gpa();
    int get_credits();
    void add_item(string n, double s, double w);
    void remove_item(int k);
    void print_course();
};
#endif