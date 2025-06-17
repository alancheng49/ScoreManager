#include <iostream>
#include "courses.h"
using namespace std;

Courses::Courses(string n, int c, double g, double e, vector<Items> init) : name(n), credits(c), gpa(g), current_score(0), expected(e), items(init) {}

double Courses::calculate_score(){
    double total = 0;
    for(auto i : items){
        total += i.get_score();
    }
    current_score = total;
    return total;
}

void Courses::add_item(string n, double s, double w){
    Items new_item(n, s, w);
    items.push_back(new_item);
    calculate_score();
    return;
}

void Courses::remove_item(int k){ 
    items.erase(items.begin() + k);
    cout << k << "-th item has been removed." << endl;
    return;
}

void Courses::print_course(){
    string g_letter = find_best_letter(gpa);
    cout << name << '\t' << credits << '\t' << g_letter << '\t' << endl;
}

double Courses::get_weighted_gpa(){
    return gpa * credits;
}

int Courses::get_credits(){
    return credits;
}