#ifndef PATIENT_H
#define PATIENT_H


typedef struct
{
    int day;
    int month;
    int year;
} Date;
typedef struct {
    char name[50];
    char address[100];
    char phoneNumber[12];
} FamilyInfo;

typedef struct  {
    char id[20];
    char name[50];
    int age;
    Date dateofBirth;
    char address[100];
    char phoneNumber[12];
}PersonalInfo;

typedef struct
{
    int hasInsurance;
    Date expirationDate;
    char insuranceID[20];
} MedicalInsurance;

typedef struct
{
    int status;   //0: chua nhap vien, 1: da nhap vien
    char department[50];
    int roomNumber;
} Hospitalization;

typedef struct
{
    char allergy[200];
    char personalHistory[200];
    char familyHistory[200];
} MedicalHistory;

typedef struct
{
    char bodyStatus[200];
    char painStatus[200];
} HealthStatus;

typedef struct
{
    char mainDisease[100];
    char accompanyDiseases[100];
} Diagnosis;


typedef struct
{
    char medicationName[200];
    char dosage[50];
    char medicationTime[50];
} Medicine;

typedef struct
{
    PersonalInfo personalInfo;
    FamilyInfo familyInfo;
    MedicalInsurance medicalInsurance;
    Hospitalization hospitalization;
    
    MedicalHistory medicalHistory;
    HealthStatus healthStatus;
    char testResult[200];
    Diagnosis diagnosis;
    Medicine medicine;
} Patient;

void enter_patient_info(Patient patient);
void display_patient_info(Patient patient);
#endif
