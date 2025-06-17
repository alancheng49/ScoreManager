#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H
#include "courses.h"
using namespace std;

class Courses_list {
private:
    vector<Courses> list;
    double expected_gpa;
public:
    Courses_list(double g = 0);
    void print_list();
    void add_course();
    void remove_course(int k);
    double get_total_gpa();
    int get_current_credits();
    void gpa_prediction();
    bool Empty();
};

void print_main_menu();
void print_examine();
void option_processing(Courses_list &x);
#endif