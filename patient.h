#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100

struct Date{
    int day, month, year;
};
typedef struct {
    char name[50];
    char address[100];
    char phone[15];
} FamilyInfo;

typedef struct {
    char patientID[10];             
    char name[50];                   
    int age;                        
    Date birthDate;                 
    char gender[10];                
    char address[100];
    char phone[15];
    FamilyInfo family;
    char hasInsurance [5];                   //Có bảo hiểm y tế hay không
    Date insuranceExpiry[11];                //Hạn BHYT
    char insuranceID[20];                    //Mã BHYT
    char status[15];                         
    char department[50];
    char room[10];
    char reasonForAdmission[100];
    char medicalHistory[200];
    char allergies[100];
    char personalHistory[100];
    char familyHistory[100]; 
    char generalCondition[100];
    char painCondition[100]; 
    char testResults[200];
    char mainDiagnosis[100];
    char comorbidities[100];
    char medication[100];
    char dosage[50];
    char medicationTime[50];
} Patient;

void addPatient(Patient patients[], int *numPatients);
void editPatient(Patient patients[], int numPatients);
void deletePatient(Patient patients[], int *numPatients);
void deleteAllPatients(Patient patients[], int *numPatients);
void searchPatient(Patient patients[], int numPatients);
void savePatients(Patient patients[], int numPatients);
void loadPatients(Patient patients[], int *numPatients);

#endif
