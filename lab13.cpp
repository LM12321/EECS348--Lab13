/*
Name of Program: Lab13.cpp
Author: Logan Whitt
KUID: 3152587

Description: an buggy function that counts if there are more than 3 absences 
in a given absence record
Inputs: absent count
Outputs: if the number of absences is greater than 0

Collaborators: This code is the code from the lab page

Creation Date: 11/25/25 - 11/25/25
*/

#include <iostream>
#include <vector>

bool fail_lecture(const std::vector<int>& attendance_records){
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i){
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}

int main(){
    std::vector<int> absent_count = {0,1,0,0,10,5};
    std::cout << fail_lecture(absent_count) << std::endl;
}
