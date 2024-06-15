#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enter_patient_info(Patient patient)
{
    printf("ID: ");
    fgets(patient.personalInfo.id, 20, stdin);
    patient.personalInfo.id[strlen(patient.personalInfo.id) - 1] = '\0';
    
    printf("Name: ");
    fgets(patient.personalInfo.name, 100, stdin);
    patient.personalInfo.name[strlen(patient.personalInfo.name) - 1] = '\0';
    
    printf("Date of birth (dd/mm/yyyy): ");
    scanf("%d/%d/%d", patient.personalInfo.dateofBirth.day, patient.personalInfo.dateofBirth.month, patient.personalInfo.dateofBirth.year);
    getchar();

    printf("Address: ");
    fgets(patient.personalInfo.address, 100, stdin);
    patient.personalInfo.address[strlen(patient.personalInfo.address) - 1] = '\0';

    printf("Phone number: ");
    fgets(patient.personalInfo.phoneNumber, 12, stdin);
    patient.personalInfo.phoneNumber[strlen(patient.personalInfo.phoneNumber) - 1] = '\0';

    printf("Family info: \n");
    printf("Name: ");
    fgets(patient.familyInfo.name, 50, stdin);
    patient.familyInfo.name[strlen(patient.familyInfo.name) - 1] = '\0';

    printf("Family address: ");
    fgets(patient.familyInfo.address, 100, stdin);
    patient.familyInfo.address[strlen(patient.familyInfo.address) - 1] = '\0';

    printf("Family phone number: ");
    fgets(patient.familyInfo.phoneNumber, 12, stdin);
    patient.familyInfo.phoneNumber[strlen(patient.familyInfo.phoneNumber) - 1] = '\0';

    printf("Medical insurance: \n");
    printf("Has insurance (1: yes, 0: no): ");
    scanf("%d", &patient.medicalInsurance.hasInsurance);
    getchar();

    if (patient.medicalInsurance.hasInsurance == 1)
    {
        printf("Expiration date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", patient.medicalInsurance.expirationDate.day, patient.medicalInsurance.expirationDate.month, patient.medicalInsurance.expirationDate.year);
        getchar();

        printf("Insurance ID: ");
        fgets(patient.medicalInsurance.insuranceID, 20, stdin);
        patient.medicalInsurance.insuranceID[strlen(patient.medicalInsurance.insuranceID) - 1] = '\0';
    }

//Có nhập viện hay không
    printf("Hospitalization: \n");
    printf("Status (0: not hospitalized, 1: hospitalized): ");
    scanf("%d", &patient.hospitalization.status);
    getchar();

    if (patient.hospitalization.status == 1)
    {
        printf("Department: ");
        fgets(patient.hospitalization.department, 50, stdin);
        patient.hospitalization.department[strlen(patient.hospitalization.department) - 1] = '\0';

        printf("Room number: ");
        scanf("%d", &patient.hospitalization.roomNumber);
        getchar();
    }

//Tiền sử bệnh
    printf("Medical history: \n");
    printf("Allergy: ");
    fgets(patient.medicalHistory.allergy, 200, stdin);
    patient.medicalHistory.allergy[strlen(patient.medicalHistory.allergy) - 1] = '\0';

    printf("Personal history: ");
    fgets(patient.medicalHistory.personalHistory, 200, stdin);
    patient.medicalHistory.personalHistory[strlen(patient.medicalHistory.personalHistory) - 1] = '\0';

    printf("Family history: ");
    fgets(patient.medicalHistory.familyHistory, 200, stdin);
    patient.medicalHistory.familyHistory[strlen(patient.medicalHistory.familyHistory) - 1] = '\0';

    printf("Health status: \n");
    printf("Body status: ");
    fgets(patient.healthStatus.bodyStatus, 200, stdin);
    patient.healthStatus.bodyStatus[strlen(patient.healthStatus.bodyStatus) - 1] = '\0';

    printf("Pain status: ");
    fgets(patient.healthStatus.painStatus, 200, stdin);
    patient.healthStatus.painStatus[strlen(patient.healthStatus.painStatus) - 1] = '\0';

    printf("Test result: ");
    fgets(patient.testResult, 200, stdin);
    patient.testResult[strlen(patient.testResult) - 1] = '\0';

    printf("Diagnosis: \n");
    printf("Main disease: ");
    fgets(patient.diagnosis.mainDisease, 100, stdin);
    patient.diagnosis.mainDisease[strlen(patient.diagnosis.mainDisease) - 1] = '\0';

    printf("Accompany diseases: ");
    fgets(patient.diagnosis.accompanyDiseases, 100, stdin);
    patient.diagnosis.accompanyDiseases[strlen(patient.diagnosis.accompanyDiseases) - 1] = '\0';

//Thuốc
    printf("Medicine: \n");
    printf("Medication name: ");
    fgets(patient.medicine.medicationName, 200, stdin);
    patient.medicine.medicationName[strlen(patient.medicine.medicationName) - 1] = '\0';

    printf("Dosage: ");
    fgets(patient.medicine.dosage, 50, stdin);
    patient.medicine.dosage[strlen(patient.medicine.dosage) - 1] = '\0';

    printf("Medication time: ");
    fgets(patient.medicine.medicationTime, 50, stdin);
    patient.medicine.medicationTime[strlen(patient.medicine.medicationTime) - 1] = '\0';

    // Hỏi có muốn lưu thông tin bệnh nhân không
    printf("Do you want to save the patient information? (1: yes, 0: no): ");
    int saveOption;
    scanf("%d", &saveOption);
    getchar();

    if (saveOption == 1) {
        // Open the file in append mode
        FILE *file = fopen("/d:/Project/Patient-Management/patient.csv", "a");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
        }

        // Write the patient information to the file
        fprintf(file, "%s,%s,%d/%d/%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                patient.personalInfo.id,
                patient.personalInfo.name,
                patient.personalInfo.dateofBirth.day,
                patient.personalInfo.dateofBirth.month,
                patient.personalInfo.dateofBirth.year,
                patient.personalInfo.address,
                patient.personalInfo.phoneNumber,
                patient.familyInfo.name,
                patient.familyInfo.address,
                patient.familyInfo.phoneNumber,
                patient.medicalInsurance.hasInsurance == 1 ? "Yes" : "No",
                patient.medicalInsurance.hasInsurance == 1 ? patient.medicalInsurance.expirationDate.day : 0,
                patient.medicalInsurance.hasInsurance == 1 ? patient.medicalInsurance.expirationDate.month : 0,
                patient.medicalInsurance.hasInsurance == 1 ? patient.medicalInsurance.expirationDate.year : 0,
                patient.medicalInsurance.hasInsurance == 1 ? patient.medicalInsurance.insuranceID : "",
                patient.hospitalization.status == 1 ? "Yes" : "No",
                patient.hospitalization.status == 1 ? patient.hospitalization.department : "",
                patient.hospitalization.status == 1 ? patient.hospitalization.roomNumber : 0,
                patient.medicalHistory.allergy,
                patient.medicalHistory.personalHistory,
                patient.medicalHistory.familyHistory,
                patient.healthStatus.bodyStatus,
                patient.healthStatus.painStatus,
                patient.testResult,
                patient.diagnosis.mainDisease,
                patient.diagnosis.accompanyDiseases,
                patient.medicine.medicationName,
                patient.medicine.dosage,
                patient.medicine.medicationTime);

        // Close the file
        fclose(file);

        printf("Patient information saved to patient.csv.\n");
    } else {
        printf("Patient information not saved.\n");
    }

}    