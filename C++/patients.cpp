#include <iostream>
#include <string>
#include "patients.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void Patient::enter_personal_info()  //Nhập thông tin bệnh nhân
{
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cout << "Date of Birth (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, dateofBirth);
    cout << "Gender (1. Male, 2. Female, 3. Others): ";
    int genderChoice;
    cin >> genderChoice;
    switch (genderChoice) {
        case 1:
            gender = "Male";
            break;
        case 2:
            gender = "Female";
            break;
        case 3:
            gender = "Others";
            break;
        default:
            cout << "Invalid choice. Setting gender to Others." << endl;
            gender = "Others";
            break;
    }
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Phone: ";
    cin.ignore();
    getline(cin, phone);
    cout << "Relative's Name: ";
    cin.ignore();
    getline(cin, relativeName);
    cout << "Relative's Address: ";
    cin.ignore();
    getline(cin, relativeAddress);
    cout << "Relative's Phone: ";
    cin.ignore();
    getline(cin, relativePhone);
    cout << "Has Insurance (1. Yes, 2. No): ";
    int insuranceChoice;
    cin >> insuranceChoice;
    hasInsurance = insuranceChoice == 1;
    if (hasInsurance) {
        cout << "Insurance Expiry (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, insuranceExpiry);
        cout << "Insurance Number: ";
        cin.ignore();
        getline(cin, insuranceNumber);
    }
    cout << "Is Admitted (1. Yes, 2. No): ";
    int admittedChoice;
    cin >> admittedChoice;
    isAdmitted = admittedChoice == 1;
    if (isAdmitted) {
        cout << "Department: ";
        cin.ignore();
        getline(cin, department);
        cout << "Room Number: ";
        cin >> roomNumber;
    }

}

void Patient::enter_medical_info() //Nhập thông tin về tình trạng sức khỏe
{
    cout << "Reason: ";
    cin.ignore();
    getline(cin, reason);
    cout << "Allergies: ";
    cin.ignore();
    getline(cin, allergies);
    cout << "Personal History: ";
    cin.ignore();
    getline(cin, personalHistory);
    cout << "Family History: ";
    cin.ignore();
    getline(cin, familyHistory);
    cout << "Body Condition: ";
    cin.ignore();
    getline(cin, bodyCondition);
    cout << "Pain Condition: ";
    cin.ignore();
    getline(cin, painCondition);
    cout << "Test Results: ";
    cin.ignore();
    getline(cin, testResults);
    cout << "Main Diagnosis: ";
    cin.ignore();
    getline(cin, mainDiagnosis);
    cout << "Accompanying Diagnosis: ";
    cin.ignore();
    getline(cin, accompanyDiagnosis);
}

string Patient::to_CSV() //Chuyển thông tin bệnh nhân sang dạng CSV
{
    return id + "," + name + "," + to_string(age) + "," + dateofBirth + "," + gender + "," + address + "," + phone + "," + relativeName + "," + relativeAddress + "," + relativePhone + "," + to_string(hasInsurance) + "," + insuranceExpiry + "," + insuranceNumber + "," + to_string(isAdmitted) + "," + department + "," + to_string(roomNumber) + "," + reason + "," + allergies + "," + personalHistory + "," + familyHistory + "," + bodyCondition + "," + painCondition + "," + testResults + "," + mainDiagnosis + "," + accompanyDiagnosis;
}

void Patient::from_CSV(string csv) //Chuyển thông tin từ dạng CSV sang thông tin bệnh nhân
{
    stringstream ss(csv);
    getline(ss, id, ',');
    getline(ss, name, ',');
    string ageStr;
    getline(ss, ageStr, ',');
    age = stoi(ageStr);
    getline(ss, dateofBirth, ',');
    getline(ss, gender, ',');
    getline(ss, address, ',');
    getline(ss, phone, ',');
    getline(ss, relativeName, ',');
    getline(ss, relativeAddress, ',');
    getline(ss, relativePhone, ',');
    string hasInsuranceStr;
    getline(ss, hasInsuranceStr, ',');
    hasInsurance = stoi(hasInsuranceStr);
    getline(ss, insuranceExpiry, ',');
    getline(ss, insuranceNumber, ',');
    string isAdmittedStr;
    getline(ss, isAdmittedStr, ',');
    isAdmitted = stoi(isAdmittedStr);
    getline(ss, department, ',');
    string roomNumberStr;
    getline(ss, roomNumberStr, ',');
    roomNumber = stoi(roomNumberStr);
    getline(ss, reason, ',');
    getline(ss, allergies, ',');
    getline(ss, personalHistory, ',');
    getline(ss, familyHistory, ',');
    getline(ss, bodyCondition, ',');
    getline(ss, painCondition, ',');
    getline(ss, testResults, ',');
    getline(ss, mainDiagnosis, ',');
    getline(ss, accompanyDiagnosis, ',');


}

void Patient::display_patient() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Date of Birth: " << dateofBirth << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Relative's Name: " << relativeName << endl;
    cout << "Relative's Address: " << relativeAddress << endl;
    cout << "Relative's Phone: " << relativePhone << endl;
    cout << "Has Insurance: " << (hasInsurance ? "Yes" : "No") << endl;
    if (hasInsurance) {
        cout << "Insurance Expiry: " << insuranceExpiry << endl;
        cout << "Insurance Number: " << insuranceNumber << endl;
    }
    cout << "Is Admitted: " << (isAdmitted ? "Yes" : "No") << endl;
    if (isAdmitted) {
        cout << "Department: " << department << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
    cout << "Reason: " << reason << endl;
    cout << "Allergies: " << allergies << endl;
    cout << "Personal History: " << personalHistory << endl;
    cout << "Family History: " << familyHistory << endl;
    cout << "Body Condition: " << bodyCondition << endl;
    cout << "Pain Condition: " << painCondition << endl;
    cout << "Test Results: " << testResults << endl;
    cout << "Main Diagnosis: " << mainDiagnosis << endl;
    cout << "Accompanying Diagnosis: " << accompanyDiagnosis << endl;

}

void PatientManager::add_patient() // Thêm thông tin bệnh nhân vào vector patients
 {
    Patient p;
    p.enter_personal_info();
    p.enter_medical_info();
    patients.push_back(p);
}

void PatientManager::edit_patient(string id) // Sửa thông tin bệnh nhân
{
    for (Patient &p : patients) {
            if (p.id == id) {
                p.display_patient();
                string choice;
                cout << "Do you want to edit personal information? (y/n): ";
                cin >> choice;
                if (choice == "y" || choice == "Y") {
                    p.enter_personal_info();
                }
                cout << "Do you want to edit medical information? (y/n): ";
                cin >> choice;
                if (choice == "y" || choice == "Y") {
                    p.enter_medical_info();
                }
                return;
            }
        }
        cout << "Patient not found." << endl;
}

void PatientManager::delete_patient(string id) //Xóa thông tin bệnh nhân
{
    for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (it->id == id) {
                cout << "Are you sure you want to delete this patient? (y/n): ";
                string choice;
                cin >> choice;
                if (choice == "y" || choice == "Y") {
                    patients.erase(it);
                    cout << "Patient deleted." << endl;
                }
                return;
            }
        }
        cout << "Patient not found." << endl;
}
void PatientManager::delete_all_patients() {
    cout << "Are you sure you want to delete all patients? (y/n): ";
    string choice;
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        patients.clear();
        cout << "All patients deleted." << endl;
    }
}

void PatientManager::search_patient(string id) //   Tìm kiếm thông tin bệnh nhân, đồng thời có 2 options sửa hoặc xóa 
 {
    for (Patient &p : patients) {
            if (p.id == id) {
                p.display_patient();
                cout << "Options:\n1. Edit Information\n2. Delete\n3. Other\nChoice: ";
                int choice;
                cin >> choice;
                if (choice == 1) {
                    edit_patient(id);
                } else if (choice == 2) {
                    delete_patient(id);
                } else if (choice == 3) {
                    cout << "1. Search Again\n2. Exit\nChoice: ";
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Enter Patient ID: ";
                        cin >> id;
                        search_patient(id);
                    } else {
                        return;
                    }
                }
                return;
            }
        }
        cout << "Patient not found." << endl;
}

void PatientManager::save_to_file(string filename) //Hàm lưu thông tin bệnh nhân vào file
{
    ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }
        for (Patient p : patients) {
            file << p.to_CSV();
        }
        file.close();
}

void PatientManager::load_from_file(string filename) //Hàm đọc thông tin bệnh nhân từ file
{
    ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            Patient p;
            p.from_CSV(line);
            patients.push_back(p);
        }
        file.close();
}

