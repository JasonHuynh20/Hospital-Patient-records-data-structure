

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20

int quit();
void printStructSize();
int menu();


int main(int argc, char **argv) {

  int numRecords = 0;         // number of records to be created

  //if the user has not inputed enough arguments to create the number of records play error message
  if(argc < 2){
    printf("Invoking the program: program_name number_of_records\nFor example: hospital 37\n");
    return 0;
  }
  

  //create number of records
  numRecords = atoi(argv[1]);

  //allocate enough memory for number of records
  PersonRec *personMemory = malloc(sizeof(PersonRec)* numRecords);

  //check if allocation failed
  if(personMemory == NULL){
    printf("Unsucessful\n");
  return 1;
  }

  // populating the array person with data of patients and employees
  populateRecords(personMemory, numRecords);
  

  //switch cases to acess menu and options
  while(1){
    switch(menu()){
      //option to end program
      case 0: if(quit() == 0){return 0;}
              else{break;};

      //print all the employees
      case 1: printEmployees(personMemory, numRecords); break;

      //search patients by family name
      case 2: searchPatients(personMemory, numRecords); break;

      //print employee summary
      case 3: printEmployeesSummary(personMemory, numRecords); break;

      //print patient summary
      case 4: printPatientSummary(personMemory,numRecords); break;

      //print the size of structures
      case 5: printStructSize(); break;

      //if user input is not vaild, ask for valid input and reprint menu
      default: printf("Please enter a valid option (0, 1, 2, 3, 4, 5) \n"); continue;
    }
  }

  //free the allocated memory
  free(personMemory);
  return 0;
}


/***********************************************************************************/
/* Displays a menu of options and records the user input

input
userInput - The user must enter one of the valid options (0, 1, 2, 3, 4, 5)

output
userInput - the input is recorded and returned for the program to later manipulate

assumption - user input is valid
*/
int menu(){
  //declare variable to store user input
  int userInput;

  //print instructions to use menu
  printf("\nPlease choose one of the options (0, 1, 2, 3, 4, 5)\n");

  //print the menu
  printf("1. Print all employees\n2. Search for all patients by Family Name\n3. Summary of Employees Data\n4. Summary of Patients data\n5. Size of structures(PersonRec, PatientRec and EmployeeRec)\n0. Quit\n");
  
  //store user input then return it
  scanf("%d",&userInput);
  return userInput;
}

/***********************************************************************************/
/* Prints out the sizes of structures PersonRec, EmployeeRec, and PatientRec

input
There is no input

output
Prints the sizes of the 3 structures

assumption - the structres are defined
*/
void printStructSize(){
  //print title, then sizes of structs
  printf("Size of Structs\n");
  printf("Size of PersonRec = %ld\n",sizeof(PersonRec));
  printf("Size of EmployeeRec = %ld\n",sizeof(EmployeeRec));
  printf("Size of PatientRec = %ld\n",sizeof(PatientRec));
}

/***********************************************************************************/
/* Ensures that the user wants to quit the program

input
userInput - The user must enter one of the valid options "y", "n"

output
print out confirmation statement and ends the program

assumption - user input is a valid 1 letter string
*/
int quit(){
  //declare variable to store user input
  char answer[100];

  //confirmation if user wants to quit
  printf("Are you sure you want to quit? (y/n)\n");
  scanf("%s", answer);

  //if want to quit return 0, if anything else return 1
  if (strcmp(answer, "y") == 0) {
    return 0;
  }
  return 1;
}



