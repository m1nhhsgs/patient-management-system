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
//Nhập thông tin bệnh nhân
void enter_patient_info(){
    Patient p;
    printf("1. Enter personal information\n");
    fflush(stdin); // Clear the input buffer (stdin)
    printf("ID: ");
    fgets(p.personalInfo.id, sizeof(p.personalInfo.id), stdin);
    p.personalInfo.id[strcspn(p.personalInfo.id, "\n")] = '\0';
    fflush(stdin);

    printf("Name: ");
    fgets(p.personalInfo.name, sizeof(p.personalInfo.name), stdin);
    p.personalInfo.name[strcspn(p.personalInfo.name, "\n")] = '\0';
    fflush(stdin);
    
    printf("Age: ");
    scanf("%d", &p.personalInfo.age);
    getchar();

    printf("Date of birth (DD/MM/YYYY): ");
    fgets(p.personalInfo.dateofBirth, 15, stdin);
    p.personalInfo.dateofBirth[strlen(p.personalInfo.dateofBirth) - 1] = '\0';
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
    fflush(stdin);
    printf("Address: ");
    fgets(p.personalInfo.address, 100, stdin);
    p.personalInfo.address[strlen(p.personalInfo.address) - 1] = '\0';
    printf("Phone: ");
    fgets(p.personalInfo.phone, 20, stdin);
    p.personalInfo.phone[strlen(p.personalInfo.phone) - 1] = '\0';
    printf("Relative name: ");
    fgets(p.personalInfo.relativeName, 50, stdin);
    p.personalInfo.relativeName[strlen(p.personalInfo.relativeName) - 1] = '\0';
    printf("Relative address: ");
    fgets(p.personalInfo.relativeAddress, 100, stdin);
    p.personalInfo.relativeAddress[strlen(p.personalInfo.relativeAddress) - 1] = '\0';
    printf("Relative phone: ");
    fgets(p.personalInfo.relativePhone, 20, stdin);
    printf("Has insurance (1. Yes, 0. No): ");
    scanf("%d", &p.personalInfo.hasInsurance);
    if (p.personalInfo.hasInsurance) {
        fflush(stdin);
        printf("Insurance expiry (DD/MM/YYYY): ");
        fgets(p.personalInfo.insuranceExpiry, 11, stdin);
        p.personalInfo.insuranceExpiry[strlen(p.personalInfo.insuranceExpiry) - 1] = '\0';
        fflush(stdin); 
        printf("Insurance number: ");
        fgets(p.personalInfo.insuranceNumber, 20, stdin);
        p.personalInfo.insuranceNumber[strlen(p.personalInfo.insuranceNumber) - 1] = '\0';
    }
    
    printf("Is Admitted (1. Yes, 0. No): ");
    scanf("%d", &p.personalInfo.isAdmitted);
    fflush(stdin);
    if (p.personalInfo.isAdmitted) {
        printf("Department: ");
        fgets(p.personalInfo.department, 50, stdin);
        p.personalInfo.department[strlen(p.personalInfo.department) - 1] = '\0';
        fflush(stdin); 
        printf("Room Number: ");
        scanf("%d", &p.personalInfo.roomNumber);
    }
    fflush(stdin); 
    printf("2. Enter medical record\n");
    printf("Reason: ");
    fgets(p.medicalRecord.reason, 100, stdin);
    p.medicalRecord.reason[strlen(p.medicalRecord.reason) - 1] = '\0';
    fflush(stdin); 
    printf("Allergies: ");
    fgets(p.medicalRecord.allergies, 100, stdin);
    p.medicalRecord.allergies[strlen(p.medicalRecord.allergies) - 1] = '\0';
    fflush(stdin); 
    printf("Personal history: ");
    fgets(p.medicalRecord.personalHistory, 100, stdin);
    p.medicalRecord.personalHistory[strlen(p.medicalRecord.personalHistory) - 1] = '\0';
    fflush(stdin); 
    printf("Family history: ");
    fgets(p.medicalRecord.familyHistory, 100, stdin);
    p.medicalRecord.familyHistory[strlen(p.medicalRecord.familyHistory) - 1] = '\0';
    fflush(stdin); 
    printf("Body condition: ");
    fgets(p.medicalRecord.bodyCondition, 100, stdin);
    p.medicalRecord.bodyCondition[strlen(p.medicalRecord.bodyCondition) - 1] = '\0';
    fflush(stdin); 
    printf("Pain condition: ");
    fgets(p.medicalRecord.painCondition, 100, stdin);
    p.medicalRecord.painCondition[strlen(p.medicalRecord.painCondition) - 1] = '\0';
    fflush(stdin); 
    printf("Test results: ");
    fgets(p.medicalRecord.testResults, 200, stdin);
    p.medicalRecord.testResults[strlen(p.medicalRecord.testResults) - 1] = '\0';
    fflush(stdin); 
    printf("Main diagnosis: ");
    fgets(p.medicalRecord.mainDiagnosis, 100, stdin);
    p.medicalRecord.mainDiagnosis[strlen(p.medicalRecord.mainDiagnosis) - 1] = '\0';
    fflush(stdin); 
    printf("Accompany diagnosis: ");
    fgets(p.medicalRecord.accompanyDiagnosis, 100, stdin);
    p.medicalRecord.accompanyDiagnosis[strlen(p.medicalRecord.accompanyDiagnosis) - 1] = '\0';
    fflush(stdin); 
    patients[patientCount++] = p;
    save_to_file();
}

//Sửa thông tin bệnh nhân, tìm kiếm bằng ID hoặc tên
void edit_patient_info() {
    char id[20];
    char name[50];
    printf("Search patient by ID (choose 1) or name (choose 2): ");
    int searchChoice;
    scanf("%d", &searchChoice);
    fflush(stdin); 
    if (searchChoice == 1) // Search by ID
    {
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
                fflush(stdin);
                printf("1. ID: ");
                fgets(patients[i].personalInfo.id, 20, stdin);
                patients[i].personalInfo.id[strlen(patients[i].personalInfo.id) - 1] = '\0';
                fflush(stdin);
                printf("2. Name: ");
                fgets(patients[i].personalInfo.name, 50, stdin);
                patients[i].personalInfo.name[strlen(patients[i].personalInfo.name) - 1] = '\0';
                fflush(stdin);
                printf("3. Age: ");
                scanf("%d", &patients[i].personalInfo.age);
                fflush(stdin);
                printf("4. Date of birth (DD/MM/YYYY): ");
                fgets(patients[i].personalInfo.dateofBirth, 15, stdin);
                patients[i].personalInfo.dateofBirth[strlen(patients[i].personalInfo.dateofBirth) - 1] = '\0';
                fflush(stdin);
                printf("5. Address: ");
                fgets(patients[i].personalInfo.address, 100, stdin);
                patients[i].personalInfo.address[strlen(patients[i].personalInfo.address) - 1] = '\0';
                fflush(stdin);
                printf("6. Phone: ");
                fgets(patients[i].personalInfo.phone, 20, stdin);
                patients[i].personalInfo.phone[strlen(patients[i].personalInfo.phone) - 1] = '\0';
                fflush(stdin);
                printf("7. Relative name: ");
                fgets(patients[i].personalInfo.relativeName, 50, stdin);
                patients[i].personalInfo.relativeName[strlen(patients[i].personalInfo.relativeName) - 1] = '\0';
                fflush(stdin);
                printf("8. Relative address: ");
                fgets(patients[i].personalInfo.relativeAddress, 100, stdin);
                patients[i].personalInfo.relativeAddress[strlen(patients[i].personalInfo.relativeAddress) - 1] = '\0';
                fflush(stdin);
                printf("9. Relative phone: ");
                fgets(patients[i].personalInfo.relativePhone, 20, stdin);
                patients[i].personalInfo.relativePhone[strlen(patients[i].personalInfo.relativePhone) - 1] = '\0';
                fflush(stdin);
                printf("10. Has insurance (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.hasInsurance);
                if (patients[i].personalInfo.hasInsurance) {
                    fflush(stdin);
                    printf("11. Insurance expiry (DD/MM/YYYY): ");
                    fgets(patients[i].personalInfo.insuranceExpiry, 11, stdin);
                    patients[i].personalInfo.insuranceExpiry[strlen(patients[i].personalInfo.insuranceExpiry) - 1] = '\0';
                    fflush(stdin);
                    printf("12. Insurance number: ");
                    fgets(patients[i].personalInfo.insuranceNumber, 20, stdin);
                }
                printf("13. Is Admitted (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.isAdmitted);
                if (patients[i].personalInfo.isAdmitted) {
                    fflush(stdin);
                    printf("14. Department: ");
                    fgets(patients[i].personalInfo.department, 50, stdin);
                    fflush(stdin);
                    printf("15. Room Number: ");
                    scanf("%d", &patients[i].personalInfo.roomNumber);
                }

                save_to_file();
                printf("Patient information updated\n");

            }

            if (choice == 2) {
                fflush(stdin);
                printf("1. Reason: ");
                fgets(patients[i].medicalRecord.reason, 100, stdin);
                patients[i].medicalRecord.reason[strlen(patients[i].medicalRecord.reason) - 1] = '\0';
                fflush(stdin);
                printf("2. Allergies: ");
                fgets(patients[i].medicalRecord.allergies, 100, stdin);
                patients[i].medicalRecord.allergies[strlen(patients[i].medicalRecord.allergies) - 1] = '\0';
                fflush(stdin);
                printf("3. Personal history: ");
                fgets(patients[i].medicalRecord.personalHistory, 100, stdin);
                patients[i].medicalRecord.personalHistory[strlen(patients[i].medicalRecord.personalHistory) - 1] = '\0';
                fflush(stdin);
                printf("4. Family history: ");
                fgets(patients[i].medicalRecord.familyHistory, 100, stdin);
                patients[i].medicalRecord.familyHistory[strlen(patients[i].medicalRecord.familyHistory) - 1] = '\0';
                fflush(stdin);
                printf("5. Body condition: ");
                fgets(patients[i].medicalRecord.bodyCondition, 100, stdin);
                patients[i].medicalRecord.bodyCondition[strlen(patients[i].medicalRecord.bodyCondition) - 1] = '\0';
                fflush(stdin);
                printf("6. Pain condition: ");
                fgets(patients[i].medicalRecord.painCondition, 100, stdin);
                patients[i].medicalRecord.painCondition[strlen(patients[i].medicalRecord.painCondition) - 1] = '\0';
                fflush(stdin);
                printf("7. Test results: ");
                fgets(patients[i].medicalRecord.testResults, 200, stdin);
                patients[i].medicalRecord.testResults[strlen(patients[i].medicalRecord.testResults) - 1] = '\0';
                fflush(stdin);
                printf("8. Main diagnosis: ");
                fgets(patients[i].medicalRecord.mainDiagnosis, 100, stdin);
                patients[i].medicalRecord.mainDiagnosis[strlen(patients[i].medicalRecord.mainDiagnosis) - 1] = '\0';
                fflush(stdin);
                printf("9. Accompany diagnosis: ");
                fgets(patients[i].medicalRecord.accompanyDiagnosis, 100, stdin);
                patients[i].medicalRecord.accompanyDiagnosis[strlen(patients[i].medicalRecord.accompanyDiagnosis) - 1] = '\0';
                fflush(stdin);

                printf("Medical record updated\n");
                save_to_file();
            }

            return;
        }
        
    }
        printf("Patient not found\n");
    } 
    else if (searchChoice == 2) //Search by name    
    {
        printf("Enter name to edit: ");
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = '\0';
        for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].personalInfo.name, name) == 0) {
            printf("Editing patient: %s\n", patients[i].personalInfo.name);

            printf("Choose part you want to edit:\n");
            printf("1. Personal information\n");
            printf("2. Medical record\n");

            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                fflush(stdin);
                printf("1. ID: ");
                fgets(patients[i].personalInfo.id, 20, stdin);
                patients[i].personalInfo.id[strlen(patients[i].personalInfo.id) - 1] = '\0';
                fflush(stdin);
                printf("2. Name: ");
                fgets(patients[i].personalInfo.name, 50, stdin);
                patients[i].personalInfo.name[strlen(patients[i].personalInfo.name) - 1] = '\0';
                fflush(stdin);
                printf("3. Age: ");
                scanf("%d", &patients[i].personalInfo.age);
                fflush(stdin);
                printf("4. Date of birth (DD/MM/YYYY): ");
                fgets(patients[i].personalInfo.dateofBirth, 15, stdin);
                patients[i].personalInfo.dateofBirth[strlen(patients[i].personalInfo.dateofBirth) - 1] = '\0';
                fflush(stdin);
                printf("5. Address: ");
                fgets(patients[i].personalInfo.address, 100, stdin);
                patients[i].personalInfo.address[strlen(patients[i].personalInfo.address) - 1] = '\0';
                fflush(stdin);
                printf("6. Phone: ");
                fgets(patients[i].personalInfo.phone, 20, stdin);
                patients[i].personalInfo.phone[strlen(patients[i].personalInfo.phone) - 1] = '\0';
                fflush(stdin);
                printf("7. Relative name: ");
                fgets(patients[i].personalInfo.relativeName, 50, stdin);
                patients[i].personalInfo.relativeName[strlen(patients[i].personalInfo.relativeName) - 1] = '\0';
                fflush(stdin);
                printf("8. Relative address: ");
                fgets(patients[i].personalInfo.relativeAddress, 100, stdin);
                patients[i].personalInfo.relativeAddress[strlen(patients[i].personalInfo.relativeAddress) - 1] = '\0';
                fflush(stdin);
                printf("9. Relative phone: ");
                fgets(patients[i].personalInfo.relativePhone, 20, stdin);
                patients[i].personalInfo.relativePhone[strlen(patients[i].personalInfo.relativePhone) - 1] = '\0';
                fflush(stdin);
                printf("10. Has insurance (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.hasInsurance);
                if (patients[i].personalInfo.hasInsurance) {
                    fflush(stdin);
                    printf("11. Insurance expiry (DD/MM/YYYY): ");
                    fgets(patients[i].personalInfo.insuranceExpiry, 11, stdin);
                    patients[i].personalInfo.insuranceExpiry[strlen(patients[i].personalInfo.insuranceExpiry) - 1] = '\0';
                    fflush(stdin);
                    printf("12. Insurance number: ");
                    fgets(patients[i].personalInfo.insuranceNumber, 20, stdin);
                }
                printf("13. Is Admitted (1. Yes, 0. No): ");
                scanf("%d", &patients[i].personalInfo.isAdmitted);
                if (patients[i].personalInfo.isAdmitted) {
                    fflush(stdin);
                    printf("14. Department: ");
                    fgets(patients[i].personalInfo.department, 50, stdin);
                    fflush(stdin);
                    printf("15. Room Number: ");
                    scanf("%d", &patients[i].personalInfo.roomNumber);
                }

                save_to_file();
                printf("Patient information updated\n");

            }

            if (choice == 2) {
                fflush(stdin);
                printf("1. Reason: ");
                fgets(patients[i].medicalRecord.reason, 100, stdin);
                patients[i].medicalRecord.reason[strlen(patients[i].medicalRecord.reason) - 1] = '\0';
                fflush(stdin);
                printf("2. Allergies: ");
                fgets(patients[i].medicalRecord.allergies, 100, stdin);
                patients[i].medicalRecord.allergies[strlen(patients[i].medicalRecord.allergies) - 1] = '\0';
                fflush(stdin);
                printf("3. Personal history: ");
                fgets(patients[i].medicalRecord.personalHistory, 100, stdin);
                patients[i].medicalRecord.personalHistory[strlen(patients[i].medicalRecord.personalHistory) - 1] = '\0';
                fflush(stdin);
                printf("4. Family history: ");
                fgets(patients[i].medicalRecord.familyHistory, 100, stdin);
                patients[i].medicalRecord.familyHistory[strlen(patients[i].medicalRecord.familyHistory) - 1] = '\0';
                fflush(stdin);
                printf("5. Body condition: ");
                fgets(patients[i].medicalRecord.bodyCondition, 100, stdin);
                patients[i].medicalRecord.bodyCondition[strlen(patients[i].medicalRecord.bodyCondition) - 1] = '\0';
                fflush(stdin);
                printf("6. Pain condition: ");
                fgets(patients[i].medicalRecord.painCondition, 100, stdin);
                patients[i].medicalRecord.painCondition[strlen(patients[i].medicalRecord.painCondition) - 1] = '\0';
                fflush(stdin);
                printf("7. Test results: ");
                fgets(patients[i].medicalRecord.testResults, 200, stdin);
                patients[i].medicalRecord.testResults[strlen(patients[i].medicalRecord.testResults) - 1] = '\0';
                fflush(stdin);
                printf("8. Main diagnosis: ");
                fgets(patients[i].medicalRecord.mainDiagnosis, 100, stdin);
                patients[i].medicalRecord.mainDiagnosis[strlen(patients[i].medicalRecord.mainDiagnosis) - 1] = '\0';
                fflush(stdin);
                printf("9. Accompany diagnosis: ");
                fgets(patients[i].medicalRecord.accompanyDiagnosis, 100, stdin);
                patients[i].medicalRecord.accompanyDiagnosis[strlen(patients[i].medicalRecord.accompanyDiagnosis) - 1] = '\0';
                fflush(stdin);

                printf("Medical record updated\n");
                save_to_file();
            }

            return;
        }
    
    }
    printf("Patient not found\n");
    } 
    else {
        printf("Invalid choice\n");
        return;
    }

}

void search_patient() //Tìm kiếm bệnh nhân bằng ID hoặc tên và hiển thị
{
    char id[20];
    char name[50];
    printf("Search patient by ID (choose 1) or name (choose 2): ");
    int searchChoice;
    scanf("%d", &searchChoice);
    fflush(stdin);
    if (searchChoice == 1) {
    fflush(stdin);
    printf("Enter ID to search: ");
    scanf(" %s", id);
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
    if (searchChoice == 2) {
        fflush(stdin);
        printf("Enter name to search: ");
        fgets(name, 50, stdin);
        name[strlen(name) - 1] = '\0';
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
}    

void delete_patient() //Xóa bệnh nhân bằng ID 
{
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

void delete_all_patients() //Xóa hết các bệnh nhân
{
    patientCount = 0;
    save_to_file();
    printf("All patients deleted\n");
}
