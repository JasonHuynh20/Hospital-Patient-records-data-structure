#include "employee.h"
#include "stdio.h"

/***********************************************************************************/
/* Prints out the data of employee that is specififed

input
person - The person that is an employee that is wanted to be printed

output
print out all of the information of the employee

assumption - person is an employee with valid data
*/
void printEmployee(PersonRec person){
  //declare variable for employee name and employee total salary
  char tempString[100];
  float totalSalary = (person.emp.salary * person.emp.yearsService);

  //print out employee information with corrected format
  sprintf(tempString,"%s %s", person.firstName, person.familyName);
  printf("%-33s dept:%2u salary:%9.2f position:%2d years of service:%4u salary to-date: %11.2f\n",tempString, person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService, totalSalary);


}

/***********************************************************************************/
/* Prints out all of the employee data that has been formatted

input
*person - A pointer to an array of person structres
numRecords - the number of person structres in the array

output
print out every employee and thier data

assumption - *person and numRecords is vaild
*/
void printEmployees(PersonRec *person, int numRecords){
  //loop through every person, if employee, call print function
  for(unsigned int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 0){
      printEmployee(person[i]);
    }
  }
}

/***********************************************************************************/
/* Prints out all of the employees information summerized based on thier position

input
*person - A pointer to an array of person structres
numRecords - the number of person structres in the array

output
print out a summary of employees and data based on their positions

assumption - *person and numRecords is vaild
*/
void printEmployeesSummary(PersonRec *person, int numRecords){
  //initialize and set counters for total salary and number of employees
  unsigned int numEmployees = 0;
  float totalSalary = 0.00;

  //initialise array to keep track of employees and salary for each position (0-3)
  int employeeNums[] = {0,0,0,0};
  float positionSalary[] = {0,0,0,0};

  //loop though all persons and count number of employees and thier salary
  for(unsigned int i = 0; i < numRecords; i++){
    if(person[i].emplyeeOrPatient == 0){
      numEmployees++;
      totalSalary += person->emp.salary;
    }
  }

  //print the information collected
  printf("Employee Summary\n");
  printf("Total number of employees:%3d total salary:%10.2f average salary:%8.2f\n", numEmployees, totalSalary,(totalSalary/numEmployees));

  //loop through all persons and keep track of number of employees for each position
  for(int i = 0; i < numRecords; i++){

    //make sure they are employee
    if(person[i].emplyeeOrPatient == 0){

      //position 0
      if(person[i].emp.position == 0){
        employeeNums[0] += 1;
        positionSalary[0] += person[i].emp.salary;
      //position 1
      }else if(person[i].emp.position == 1){
        employeeNums[1] += 1;
        positionSalary[1] += person[i].emp.salary;
      //position 2
      }else if(person[i].emp.position == 2){
        employeeNums[2] += 1;
        positionSalary[2] += person[i].emp.salary;
      //position 3
      }else if(person[i].emp.position == 3){
        employeeNums[3] += 1;
        positionSalary[3] += person[i].emp.salary;
      }
    }
  }

  //loop and print the summary for each position
  printf("Summary by position\n");
  for(int i = 0; i < 4; i++){
    printf("position[%d] - employees:%2d total salary:%9.2f average salary:%8.2f\n", i, employeeNums[i], positionSalary[i], (positionSalary[i]/employeeNums[i]));
  }
}
