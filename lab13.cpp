/*
Name of Program: Lab13.cpp
Author: Logan Whitt
KUID: 3152587

Description: an overview of a buggy program vs the fixed one
and their differences
Inputs: absent count
Outputs: if the number of absences is greater than 0

Collaborators: This code is the code from the lab page

Creation Date: 11/25/25 - 11/25/25
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool fail_lecture_bad(const vector<int>& attendance_records){
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i){
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}
bool fail_lecture_good(const vector<int>& attendance_records){
    int absent_count = 0;
    for (int i = 0; i < attendance_records.size(); ++i){
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}

string convert_vector_to_string(const vector<int>& attendance_records){
    string output_string = "{"; //start the string with the beginning brace
    for (int i = 0; i < 10; i++){   //iterate through all 10 items
        output_string += to_string(attendance_records[i]);  //convert the element to string and add it
        if (i != 9){    //if we aren't at the last element
            output_string += ", ";  //add a comma and space for later entries
        }
    }
    output_string += "}";   //add the ending brace
    return output_string;   //return the new string
}

int main(){
    //initalize different tests
    vector<int> test_one = {1,1,0,0,1,1,0,0,0,0};
    vector<int> test_two = {0,1,0,0,0,1,1,1,1,1};
    vector<int> test_three = {0,0,0,1,1,1,1,1,1,1};
    vector<vector<int>> programs = {test_one, test_two, test_three};    //make a vector for easy simplification

    for (int i = 0; i < 3; i++){    //for each of the three tests
        cout << "Test " << i+1 <<  ": " << endl;
        cout << "Input: " << convert_vector_to_string(programs[i]) << endl; 
        cout << "Expected Result: " << fail_lecture_good(programs[i]) << endl;
        cout << "Actual Result: " << fail_lecture_bad(programs[i]) << endl;
        cout << endl;
    }

}