#include "main_func.h"
#include <iostream>
#include <iomanip>

void print_main_menu(){
    cout << endl;
    cout << "===Score Manager(v1.0)===" << endl;
    cout << "1: Show all courses" << endl;
    cout << "2: Add a course" << endl;
    cout << "3: Delete a course" << endl;
    cout << "4: GPA prediction" << endl;
    cout << "5: Settings" << endl;
    cout << "6: Quit" << endl;
    return;
}

void option_processing(Courses_list &x){
    bool flag = true;
    while(flag){
        print_main_menu();
        cout << "Please input an integer to access specific function: ";
        int opt;
        cin >> opt;
        if(cin.fail() || (opt < 1 || opt > 6)){
            cin.clear();
            cin.ignore(INT32_MAX, '\n');
            cout << "Please input a valid integer!" << endl;
            continue;
        }

        switch (opt){
            case 1: {
                x.print_list();
                if(x.Empty()) break;
                cout << "Examine a course? [y/n]: ";
                string option;
                cin >> option;
                if(option == "y"){
                    cout << "Still working on it..." << endl;
                }
                break;
            }
            case 2:
                x.add_course();
                break;
            case 3: {
                x.print_list();
                cout << "Please input an integer to delete a course: ";
                int n;
                cin >> n;
                x.remove_course(n);
                break;
            }
            case 4: {
                x.gpa_prediction();
                break;
            }
            case 5: {
                cout << "Version: 1.0" << endl;
                break;
            }
            case 6: {
                flag = false;
                break;
            }
            default: 
                cout << "Invalid input or function not supported." << endl;
                break;
        }

    }

}

Courses_list::Courses_list(double g) : expected_gpa(g), list() {}

void Courses_list::print_list(){
    if(list.empty()){
        cout << "No courses existing. Back to menu." << endl;
        return;
    }
    cout << "Name/Credits/GPA\n";
    cout << string(30, '-') << endl;
    int index = 0;
    for(auto i : list){
        cout << index << ": ";
        i.print_course();
        index++;
    }
    return;
}

void Courses_list::add_course(){
    string n, g_letter;
    int c;
    double g, s, e;
    cout << "Please input the name of the course: ";
    cin.ignore(1000, '\n');
    getline(cin, n);
    cout << "Please input the number of credits of the course: ";
    cin >> c;
    cout << "Please input the GPA of the score (in letter score). Input -1 instead if not determined: ";
    cin >> g_letter;
    if(g_letter == "-1"){
        cout << "Please input the expected score of this course (-1 if undetermined): ";
        cin >> s;
        if(s == -1) s = 60;
        Courses new_course(n, c, -1, s);
        list.push_back(new_course);
    }
    else{
        g = letter_to_num(g_letter);
        Items new_item("default", g, 1);
        Courses new_course(n, c, g, -1, {new_item});
        list.push_back(new_course); 
    }
    cout << n << " has been added!" << endl;
    return;
}

void Courses_list::remove_course(int k){
    list.erase(list.begin() + k);
    cout << k << "-th course has been removed." << endl;
    return;
}

double Courses_list::get_total_gpa(){
    int total_credits = 0;
    double total = 0;
    for(auto i : list){
        total_credits += i.get_credits();
        total += i.get_weighted_gpa();
    }
    return total / total_credits;
}

int Courses_list::get_current_credits(){
    int result = 0;
    for(auto i : list){
        result += i.get_credits();
    }
    return result;
}

void Courses_list::gpa_prediction(){
    double current_gpa = get_total_gpa();
    cout << "Current GPA: " << current_gpa << endl;
    cout << "Do prediction? [y/n]: ";
    string opt;
    cin >> opt;
    cout << endl;
    if(opt == "y"){
        int total_credits;
        while(true){
            cout << "Please input your expected gpa (in floating number): ";
            cin >> expected_gpa;
            cout << endl;
            if(expected_gpa < 0 || expected_gpa > 4.3){
                cout << "Not valid!" << endl;
                continue;
            }
            cout << "Please input your total credits: ";
            cin >> total_credits;
            cout << endl;
            int remain_credits = total_credits - get_current_credits();
            if(remain_credits < 0){
                cout << "Not valid!" << endl;
                continue;
            }
            double remain_avg = (expected_gpa * total_credits - current_gpa * get_current_credits()) / remain_credits;
            string result = find_best_letter(remain_avg);
            if(result == "null") result = "Seems not to be possible :(";
            else if(result == "F") result = "Your goal has been achieved!";
            cout << "The least requirement for the remaining courses is: " << result << endl;
            break;
        }
    }
    else{
        cout << "Going back to menu." << endl;
        return;
    }
    return;
}

bool Courses_list::Empty(){
    return list.empty();
}

void print_examine(){

}