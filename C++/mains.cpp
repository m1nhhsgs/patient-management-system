#include "patients.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
int main(){
    PatientManager pm;
    string filename = "patients_data.csv";
    pm.load_from_file(filename);

    while (1) {
        system("cls");
        cout << "PATIENT MANAGEMENT SYSTEM\n";
        cout << "Menu:\n1. Add Patient\n2. Delete All Patients\n3. Search Patient\n4. Save and Exit\nChoice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            system("cls");
            pm.add_patient();
        } 
        
        else if (choice == 2) {
            pm.delete_all_patients();
        } 
        else if (choice == 3) {
            string id;
            system("cls");
            cout << "Enter Patient ID to Search: ";
            cin >> id;
            pm.search_patient(id);
        } 
        else if (choice == 4) {
            pm.save_to_file(filename);
            break;

        }
    }
    return 0;
}