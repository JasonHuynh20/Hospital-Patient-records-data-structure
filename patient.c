

#include "string.h"
#include "stdio.h"
#include "patient.h"

/***********************************************************************************/
/* Prints out the specified patient's information

input
person - A person structure that is a patient


output
print out a patients information that has been formatted

assumption - person is a patient
*/
void printPatient(PersonRec person){
  //declare variable for the first and last name and set it
  char tempString[100];
  sprintf(tempString,"%s %s", person.firstName, person.familyName);
  //print out patient information thats formatted
  printf("%-33s dept:%2d Number of days in the hospital:%6.2d Severity:%2u daily cost:%u total cost:%u\n", tempString, person.patient.department, person.patient.numDaysInHospital, person.patient.severity, person.patient.dailyCost, (person.patient.dailyCost * person.patient.numDaysInHospital));

}

/***********************************************************************************/
/* Prints out all of the patients data that has been formatted

input
*person - A pointer to an array of person structres
numRecords - the number of person structres in the array

output
print out every patient and thier data

assumption - *person and numRecords is vaild
*/
void printPatients(PersonRec *person, int numRecords){
  //loop through all people, if they are a patient, call the print function
  for(int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 1){
      printPatient(person[i]);
    }
  }

}

/***********************************************************************************/
/* Prints out all of the patient's information summerized based on thier department

input
*person - A pointer to an array of person structres
numRecords - the number of person structres in the array

output
print out a summary of patients and data that has been summarized based on their departments

assumption - *person and numRecords is vaild
*/
void printPatientSummary(PersonRec *person, int numRecords){
  //declare counters to keep track of number of patients and total costs
  unsigned int numPatient = 0;
  float totalCost = 0.00;

  //declare and initialize counters based on department
  //number of patients
  int patientNums[] = {0,0,0,0,0,0};

  //total cost per department
  float departmentCosts[] = {0,0,0,0,0,0};

  //daily costs based for each department
  float dailyCost[] = {0,0,0,0,0,0};

  //loop through all the people, if they are a patient, add number of patients and costs
  for(unsigned int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 1){
      numPatient++;
      totalCost += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
    }
  }

  //print beggining of summary with total patients and required info
  printf("Patient Summary\n");
  printf("Total number of patients:%3d total cost to-date:%9.2f average cost per patient to-date:%7.2f\n", numPatient, totalCost,(totalCost/numPatient));

  //loop through all people, if they are a patient, increase patient number counter, add total and daily costs
  for(int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 1){

      //department 1
      if(person[i].patient.department == 1){
        patientNums[0] += 1;
        departmentCosts[0] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[0] += person[i].patient.dailyCost;

      //department 2
      }else if(person[i].patient.department == 2){
        patientNums[1] += 1;
        departmentCosts[1] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[1] += person[i].patient.dailyCost;

      //department 3
      }else if(person[i].patient.department == 3){
        patientNums[2] += 1;
        departmentCosts[2] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[2] += person[i].patient.dailyCost;

      //department 4
      }else if(person[i].patient.department == 4){
        patientNums[3] += 1;
        departmentCosts[3] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[3] += person[i].patient.dailyCost;

      //department 5
      }else if(person[i].patient.department == 5){
        patientNums[4] += 1;
        departmentCosts[4] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[4] += person[i].patient.dailyCost;

      //department 6
      }else if(person[i].patient.department == 6){
        patientNums[5] += 1;
        departmentCosts[5] += (person[i].patient.dailyCost * person[i].patient.numDaysInHospital);
        dailyCost[5] += person[i].patient.dailyCost;
      }
    }
  }

  //loop through the departments and print the data for each department
  printf("\nSummary by Department\n");
  for(int i = 0; i < 6; i++){
  	if((departmentCosts[i] == 0)|(patientNums[i] == 0)){
		printf("Department[%d] - Patients:%3d cost to-date:%7.2f daily cost:%7.2f average costs:%7.2f\n", (i+1), patientNums[i], departmentCosts[i], dailyCost[i], 0.00);
	}else{
   		printf("Department[%d] - Patients:%3d cost to-date:%7.2f daily cost:%7.2f average costs:%7.2f\n", (i+1), patientNums[i], departmentCosts[i], dailyCost[i], (departmentCosts[i]/patientNums[i]));
	}
  }
}


/***********************************************************************************/
/* Search through the array of person structures and print out every patient with the specified family name

input
*person - A pointer to an array of person structres
numRecords - the number of person structres in the array
targetName - The user input that represents the family's name that is wanted to be searched

output
print out all patients with the targeted family name

assumption - *person and numRecords is vaild
targetName is a vaild family name in the array
*/
void searchPatients(PersonRec *person, int numRecords){
  //declare a variable for the target name
  char targetName[100];

  //get user input
  printf("What is the family name of the patient: \n");
  scanf("%s", targetName);

  //loop through every person, if they are a patient, compare the family name and print it if it matches
  for(int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 1){
      if(strcmp(person[i].familyName,targetName) == 0){
        printPatient(person[i]);
      }
    }
  }
}
