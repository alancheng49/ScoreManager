#include <iostream>
#include "scores.h"
using namespace std;

Items::Items(string n, double s, double w) : name(n), score(s), weight(w) {}

double Items::get_score(){
    return score * weight;
}

string Items::get_name(){
    return name;
}