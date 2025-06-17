#ifndef SCORES_H
#define SCORES_H
#include <string>
#include <vector>

using namespace std;

class Items {
private:
    string name;
    double score;
    double weight;
public:
    double get_score();
    string get_name();
    Items(string n = "null", double s = 0, double w = 0);
};

#endif