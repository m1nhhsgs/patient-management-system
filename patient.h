#ifndef PATIENT_H
#define PATIENT_H
#define BUFFER_SIZE 256


typedef struct {
    char id[20];
    char name[50];
    int age;
    char dateofBirth[15];
    char gender[10];
    char address[100];
    char phone[20];
    char relativeName[50];
    char relativeAddress[100];
    char relativePhone[20];
    int hasInsurance;
    char insuranceExpiry[11];
    char insuranceNumber[20];
    int isAdmitted;
    char department[50];
    int roomNumber;
} PersonalInfo;

typedef struct {
    char reason[100];
    char allergies[100];
    char personalHistory[100];
    char familyHistory[100];
    char bodyCondition[100];
    char painCondition[100];
    char testResults[200];
    char mainDiagnosis[100];
    char accompanyDiagnosis[100];

} MedicalRecord;

typedef struct {
    PersonalInfo personalInfo;
    MedicalRecord medicalRecord;
} Patient;



void save_to_file();
void load_from_file();
void enter_patient_info();
void edit_patient_info();
void delete_patient();
void delete_all_patients();
void search_patient();
#endif
