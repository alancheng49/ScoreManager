#ifndef GPA_LETTER_MAPPING_H
#define GPA_LETTER_MAPPING_H
#include <string>
#include <vector>

using namespace std;

typedef struct {
    double num;
    string letter;
} Pair;

extern const vector<Pair> map;

double letter_to_num(string &key);
string find_best_letter(double gpa);
#endif