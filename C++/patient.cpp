#include <iostream>
#include <string>
#include "patient.hpp"
#include <fstream>
#include <conio.h>

using namespace std;

void Patient::save_to_file() {
    ofstream file("patient_data.csv", ios::app); // Open the file in append mode

    if (file.is_open()) {
        // Write patient information to the file
        file << id << "," << name << "," << age << "," << address << "," << phone << "," << dateofBirth << "," << gender << "," << relativeName << "," << relativeAddress << "," << relativePhone << "," << hasInsurance << "," << insuranceExpiry << "," << insuranceNumber << "," << isAdmitted << "," << department << "," << roomNumber << "," << reason << "," << allergies << "," << personalHistory << "," << familyHistory << "," << bodyCondition << "," << painCondition << "," << testResults << "," << mainDiagnosis << "," << accompanyDiagnosis << "\n";

        file.close(); // Close the file
        cout << "Patient data saved to file.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void Patient::load_from_file() {
    ifstream f("patient_data.csv"); // Open the file in read mode

    if (f.is_open()) {
        string line;

        while (getline(f, line)) {
            cout << line << endl;
        }

        f.close(); // Close the file
    } else {
        cout << "Unable to open file.\n";
    }
}
void Patient::enter_patient_info() {
    cout << "1. Enter personal information\n";
    cout << "ID: ";
    getline(cin, id);
    cout << "Name: ";
    getline(cin, name);

    cout << "Age: ";
    cin >> age;
    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Address: ";
    getline(cin, address);

    cout << "Phone number: ";
    getline(cin, phone);

    cout << "Date of Birth (DD/MM/YYYY): ";
    getline(cin, dateofBirth);

    cout << "Gender (Choose 1 of 3: 1. Male, 2. Female, 3. Other): ";
    int choice;
    cin >> choice;
    cin.ignore(); // Ignore the newline character left in the input buffer

    switch (choice) {
        case 1:
            gender = "Male";
            break;
        case 2:
            gender = "Female";
            break;
        case 3:
            gender = "Other";
            break;
        default:
            cout << "Invalid choice. Setting gender to Other.\n";
            gender = "Other";
            break;
    }
    
    cout << "Relative's Name: ";
    getline(cin, relativeName);

    cout << "Relative's Address: ";
    getline(cin, relativeAddress);

    cout << "Relative's Phone number: ";
    getline(cin, relativePhone);

    cout << "Does the patient have insurance? (1. Yes, 0. No): ";
    cin >> hasInsurance;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (hasInsurance) {
        cout << "Insurance Expiry Date (DD/MM/YYYY): ";
        getline(cin, insuranceExpiry);

        cout << "Insurance Number: ";
        getline(cin, insuranceNumber);
    }

    cout << "Is the patient admitted? (1. Yes, 0. No): ";
    cin >> isAdmitted;
    cin.ignore(); // Ignore the newline character left in the input buffer

    if (isAdmitted) {
        cout << "Department: ";
        getline(cin, department);

        cout << "Room Number: ";
        cin >> roomNumber;
        cin.ignore(); // Ignore the newline character left in the input buffer
    }

    cout << "2. Medical Record\n"; 
    cout << "Reason : ";
    getline(cin, reason);

    cout << "Allergies : ";
    getline(cin, allergies);

    cout << "Personal History : ";
    getline(cin, personalHistory);

    cout << "Family History : ";
    getline(cin, familyHistory);

    cout << "Body Condition : ";
    getline(cin, bodyCondition);

    cout << "Pain Condition : ";
    getline(cin, painCondition);

    cout << "Test Results : ";
    getline(cin, testResults);

    cout << "Main Diagnosis : ";
    getline(cin, mainDiagnosis);

    cout << "Accompany Diagnosis : ";
    getline(cin, accompanyDiagnosis);

    save_to_file();

}


