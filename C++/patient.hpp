#pragma once
#include <iostream>
#include <string>

using namespace std;

class Patient {
    private:
        string id;
        string name;
        int age;
        string dateofBirth;
        string gender;
        string address;
        string phone;
        string relativeName;
        string relativeAddress;
        string relativePhone;
        bool hasInsurance;
        string insuranceExpiry;
        string insuranceNumber;
        bool isAdmitted;
        string department;
        int roomNumber;

        string reason;
        string allergies;
        string personalHistory;
        string familyHistory;
        string bodyCondition;
        string painCondition;
        string testResults;
        string mainDiagnosis;
        string accompanyDiagnosis;
    
    public:
        void save_to_file();
        void load_from_file();
        void enter_patient_info();
        void edit_patient_info();   
        void delete_patient();
        void delete_all_patients();
        void search_patient();
    
};