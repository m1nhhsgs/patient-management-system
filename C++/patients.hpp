#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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
        void enter_personal_info();
        void enter_medical_info();
        string to_CSV();
        void from_CSV(string csv);
        void display_patient();

        friend class PatientManager;
};

class PatientManager {
    private:
        vector<Patient> patients;
    
    public:
        void add_patient();
        void edit_patient(string id);
        void delete_patient(string id);
        void delete_all_patients();
        void save_to_file(string filename);
        void load_from_file(string filename);
        void search_patient(string id);
};