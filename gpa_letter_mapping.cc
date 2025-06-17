#include "gpa_letter_mapping.h"
#include <iostream>

using namespace std;

const vector<Pair> map = {{0, "F"}, {1.7, "C-"}, {2, "C"}, {2.3, "C+"}, {2.7, "B-"}, {3.0, "B"}, {3.3, "B+"}, {3.7, "A-"}, {4, "A"}, {4.3, "A+"}};

double letter_to_num(string &key){
    for(auto i : map){
        if(i.letter == key){
            return i.num;
        }
    }
    return -1;
}

string find_best_letter(double gpa){
    for(auto i : map){
        if(gpa <= i.num){
            return i.letter;
        }
    }
    return "null";
}