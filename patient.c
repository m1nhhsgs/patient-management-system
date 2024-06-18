#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Patient patients[100];
int patientCount = 0;
//Lưu data vào file
void save_to_file(){
    FILE *f = fopen("patients.csv", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < patientCount; i++) {
        fprintf(f, "%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%d,%s,%s,%d,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            patients[i].personalInfo.id,
            patients[i].personalInfo.name,
            patients[i].personalInfo.age,
            patients[i].personalInfo.dateofBirth,
            patients[i].personalInfo.gender,
            patients[i].personalInfo.address,
            patients[i].personalInfo.phone,
            patients[i].personalInfo.relativeName,
            patients[i].personalInfo.relativeAddress,
            patients[i].personalInfo.relativePhone,
            patients[i].personalInfo.hasInsurance,
            patients[i].personalInfo.insuranceExpiry,
            patients[i].personalInfo.insuranceNumber,
            patients[i].personalInfo.isAdmitted,
            patients[i].personalInfo.department,
            patients[i].personalInfo.roomNumber,
            patients[i].medicalRecord.reason,
            patients[i].medicalRecord.allergies,
            patients[i].medicalRecord.personalHistory,
            patients[i].medicalRecord.familyHistory,
            patients[i].medicalRecord.bodyCondition,
            patients[i].medicalRecord.painCondition,
            patients[i].medicalRecord.testResults,
            patients[i].medicalRecord.mainDiagnosis,
            patients[i].medicalRecord.accompanyDiagnosis
        );
    }
    fclose(f);
}

// Load data từ file
void load_from_file(){
    FILE *file = fopen("patients.csv", "r");
    if (file == NULL) {
        return;
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        Patient p;
        sscanf(buffer, "%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
            p.personalInfo.id,
            p.personalInfo.name,
            &p.personalInfo.age,
            p.personalInfo.dateofBirth,
            p.personalInfo.gender,
            p.personalInfo.address,
            p.personalInfo.phone,
            p.personalInfo.relativeName,
            p.personalInfo.relativeAddress,
            p.personalInfo.relativePhone,
            &p.personalInfo.hasInsurance,
            p.personalInfo.insuranceExpiry,
            p.personalInfo.insuranceNumber,
            &p.personalInfo.isAdmitted,
            p.personalInfo.department,
            &p.personalInfo.roomNumber,
            p.medicalRecord.reason,
            p.medicalRecord.allergies,
            p.medicalRecord.personalHistory,
            p.medicalRecord.familyHistory,
            p.medicalRecord.bodyCondition,
            p.medicalRecord.painCondition,
            p.medicalRecord.testResults,
            p.medicalRecord.mainDiagnosis,
            p.medicalRecord.accompanyDiagnosis
        );
        patients[patientCount++] = p;
    }
    
    fclose(file);
}
void enter_patient_info(){
    Patient p;
    printf("1. Enter personal information\n");
    printf("ID: ");
    scanf("%s", p.personalInfo.id);
    printf("Name: ");
    scanf("%s", p.personalInfo.name);
    printf("Age: ");
    scanf("%d", &p.personalInfo.age);
    printf("Date of birth (DD/MM/YYYY): ");
    scanf("%s", p.personalInfo.dateofBirth);
    printf("Gender (Choose 1 of 3: 1. Male, 2. Female, 3. Others): ");
    int genderChoice;
    scanf("%d", &genderChoice);
    enum Gender {
        Male = 1,
        Female,
        Others
    };
    enum Gender gender;
    switch (genderChoice)
    {
        case 1:
            gender = Male;
            break;
        case 2:
            gender = Female;
            break;
        case 3:
            gender = Others;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }
    strcpy(p.personalInfo.gender, gender == Male ? "Male" : (gender == Female ? "Female" : "Others"));

    printf("Address: ");
    scanf("%s", p.personalInfo.address);
    printf("Phone: ");
    scanf("%s", p.personalInfo.phone);
    printf("Relative name: ");
    scanf("%s", p.personalInfo.relativeName);
    printf("Relative address: ");
    scanf("%s", p.personalInfo.relativeAddress);
    printf("Relative phone: ");
    scanf("%s", p.personalInfo.relativePhone);
    printf("Has insurance (1. Yes, 0. No): ");
    scanf("%d", &p.personalInfo.hasInsurance);
    if (p.personalInfo.hasInsurance) {
        printf("Insurance expiry (DD/MM/YYYY): ");
        scanf("%s", p.personalInfo.insuranceExpiry);
        printf("Insurance number: ");
        scanf("%s", p.personalInfo.insuranceNumber);
    }

    printf("Is Admitted (1. Yes, 0. No): ");
    scanf("%d", &p.personalInfo.isAdmitted);
    if (p.personalInfo.isAdmitted) {
        printf("Department: ");
        scanf("%s", p.personalInfo.department);
        printf("Room Number: ");
        scanf("%d", &p.personalInfo.roomNumber);
    }

    printf("2. Enter medical record\n");
    printf("Reason: ");
    scanf("%s", p.medicalRecord.reason);
    printf("Allergies: ");
    scanf("%s", p.medicalRecord.allergies);
    printf("Personal history: ");
    scanf("%s", p.medicalRecord.personalHistory);
    printf("Family history: ");
    scanf("%s", p.medicalRecord.familyHistory);
    printf("Body condition: ");
    scanf("%s", p.medicalRecord.bodyCondition);
    printf("Pain condition: ");
    scanf("%s", p.medicalRecord.painCondition);
    printf("Test results: ");
    scanf("%s", p.medicalRecord.testResults);
    printf("Main diagnosis: ");
    scanf("%s", p.medicalRecord.mainDiagnosis);
    printf("Accompany diagnosis: ");
    scanf("%s", p.medicalRecord.accompanyDiagnosis);

    patients[patientCount++] = p;
    save_to_file();
}

void edit_patient_info() {
    char id[20];
    printf("Enter ID to edit: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].personalInfo.id, id) == 0) {
            printf("Editing patient: %s\n", patients[i].personalInfo.name);

            printf("Choose part you want to edit:\n");
            printf("1. Personal information\n");
            printf("2. Medical record\n");

            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("1. ID: ");
                scanf("%s", patients[i].personalInfo.id);
                printf("2. Name: ");
                scanf("%s", patients[i].personalInfo.name);
                printf("3. Age: ");
                scanf("%d", &patients[i].personalInfo.age);
                printf("4. Date of birth (DD/MM/YYYY): ");
                scanf("%s", patients[i].personalInfo.dateofBirth);
                printf("5. Address: ");
                scanf("%s", patients[i].personalInfo.address);
                printf("6. Phone: ");
                scanf("%s", patients[i].personalInfo.phone);
                printf("7. Relative name: ");
                scanf("%s", patients[i].personalInfo.relativeName);
                printf("8. Relative address: ");
                scanf("%s", patients[i].personalInfo.relativeAddress);
                printf("9. Relative phone: ");
                scanf("%s", patients[i].personalInfo.relativePhone);
                printf("10. Has insurance (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.hasInsurance);
                if (patients[i].personalInfo.hasInsurance) {
                    printf("11. Insurance expiry (DD/MM/YYYY): ");
                    scanf("%s", patients[i].personalInfo.insuranceExpiry);
                    printf("12. Insurance number: ");
                    scanf("%s", patients[i].personalInfo.insuranceNumber);
                }
                printf("13. Is Admitted (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.isAdmitted);
                if (patients[i].personalInfo.isAdmitted) {
                    printf("14. Department: ");
                    scanf("%s", patients[i].personalInfo.department);
                    printf("15. Room Number: ");
                    scanf("%d", &patients[i].personalInfo.roomNumber);
                }

                save_to_file();
                printf("Patient information updated\n");

            }

            if (choice == 2) {
                printf("1. Reason: ");
                scanf("%s", patients[i].medicalRecord.reason);
                printf("2. Allergies: ");
                scanf("%s", patients[i].medicalRecord.allergies);
                printf("3. Personal history: ");
                scanf("%s", patients[i].medicalRecord.personalHistory);
                printf("4. Family history: ");
                scanf("%s", patients[i].medicalRecord.familyHistory);
                printf("5. Body condition: ");
                scanf("%s", patients[i].medicalRecord.bodyCondition);
                printf("6. Pain condition: ");
                scanf("%s", patients[i].medicalRecord.painCondition);
                printf("7. Test results: ");
                scanf("%s", patients[i].medicalRecord.testResults);
                printf("8. Main diagnosis: ");
                scanf("%s", patients[i].medicalRecord.mainDiagnosis);
                printf("9. Accompany diagnosis: ");
                scanf("%s", patients[i].medicalRecord.accompanyDiagnosis);
                
                printf("Medical record updated\n");
                save_to_file();
            }

            return;
        }
    
    }
    printf("Patient not found\n");
}

void search_patient() {
    char id[20];
    printf("Enter ID to search: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].personalInfo.id, id) == 0) {
            printf("Patient found:\n");
            printf("ID: %s\n", patients[i].personalInfo.id);
            printf("Name: %s\n", patients[i].personalInfo.name);
            printf("Age: %d\n", patients[i].personalInfo.age);
            printf("Date of birth: %s\n", patients[i].personalInfo.dateofBirth);
            printf("Adđress: %s\n", patients[i].personalInfo.address);
            printf("Phone: %s\n", patients[i].personalInfo.phone);
            printf("Relative name: %s\n", patients[i].personalInfo.relativeName);
            printf("Relative address: %s\n", patients[i].personalInfo.relativeAddress);
            printf("Relative phone: %s\n", patients[i].personalInfo.relativePhone);
            printf("Has insurance: %s\n", patients[i].personalInfo.hasInsurance ? "Yes" : "No");
            if (patients[i].personalInfo.hasInsurance) {
                printf("Insurance expiry: %s\n", patients[i].personalInfo.insuranceExpiry);
                printf("Insurance number: %s\n", patients[i].personalInfo.insuranceNumber);
            }
            printf("Is admitted: %s\n", patients[i].personalInfo.isAdmitted ? "Yes" : "No");
            if (patients[i].personalInfo.isAdmitted) {
                printf("Department: %s\n", patients[i].personalInfo.department);
                printf("Room number: %d\n", patients[i].personalInfo.roomNumber);
            }
            printf("Reason: %s\n", patients[i].medicalRecord.reason);
            printf("Allergies: %s\n", patients[i].medicalRecord.allergies);
            printf("Personal history: %s\n", patients[i].medicalRecord.personalHistory);
            printf("Family history: %s\n", patients[i].medicalRecord.familyHistory);
            printf("Body condition: %s\n", patients[i].medicalRecord.bodyCondition);
            printf("Pain condition: %s\n", patients[i].medicalRecord.painCondition);
            printf("Test results: %s\n", patients[i].medicalRecord.testResults);
            printf("Main diagnosis: %s\n", patients[i].medicalRecord.mainDiagnosis);
            printf("Accompany diagnosis: %s\n", patients[i].medicalRecord.accompanyDiagnosis);
            return;
        }    
    }
    printf("Patient not found\n");
}    

void delete_patient() {
    char id[20];
    printf("Enter ID to delete: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].personalInfo.id, id) == 0) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            save_to_file();
            printf("Patient deleted\n");
            return;
        }
    }
    printf("Patient not found\n");
}

void delete_all_patients() {
    patientCount = 0;
    save_to_file();
    printf("All patients deleted\n");
}
