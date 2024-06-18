#include <stdio.h>
#include "patient.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    
    load_from_file();
    int choice;
    
    do {
        system("cls");
        printf("PATIENT MANAGEMENT SYSTEM\n");
        printf("1. Add Patient\n");
        printf("2. Edit Patient\n");
        printf("3. Delete Patient\n");
        printf("4. Delete All Patients\n");
        printf("5. Display Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                char c1;
                c1 = 'N';
                do{
                    system("cls");
                    enter_patient_info();
                    printf("Do you want to add another patient? (Y/N): ");
                    scanf(" %c", &c1);
                }while(c1 == 'Y' || c1 == 'y');
                
                break;
            case 2:
                char c2;
                c2 = 'N';
                do{
                    system("cls");
                    edit_patient_info();
                    printf("Do you want to edit another patient? (Y/N): ");
                    scanf(" %c", &c2);
                }while(c2 == 'Y' || c2 == 'y');
                break;
            case 3:
                char c3;
                c3 = 'N';
                do{
                    system("cls");
                    delete_patient();
                    printf("Do you want to delete another patient? (Y/N): ");
                    scanf(" %c", &c3);
                }while(c3 == 'Y' || c3 == 'y');
                
                break;
            case 4:
                delete_all_patients();
                break;
            case 5:
                char c5;
                c5 = 'N';
                do{
                    system("cls");
                    search_patient();
                    printf("Do you want to search another patient? (Y/N): ");
                    scanf(" %c", &c5);
                }while(c5 == 'Y' || c5 == 'y');
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    

    return 0;
}