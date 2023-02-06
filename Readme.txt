Program author: Jason Huynh

Purpose: Create a program that accepts input of integers, turns the input chars and corrects any errors

Source files: hospital.c patient.c employee.c populateRecords.c

exact compilation command: "gcc hospital.c patient.c employee.c populateRecords.c"

Launching and operation instructions:
1. To launch the program, compile the files then type "./a.out" followed by a positive integer less than 20
	e.g "./a.out 13"
2. When you first launch the program, it will display a menu with 6 options
3. Input the number of the option that you would like to run then click enter
4. The program will run the option that you have selected then redisplay the menu for you to choose more
5. When the user wants to exit the program, choose option 0
6. After choosing option 0, a confirmation message will be promted
7. To exit, when prompted, enter "y" to confirm and the program wil exit


Software organization: For this software, there are 5 files hospital.c, patient.c, employee.c, populateRecords.c, struct.h

The hospital.c file contains the main method and a few functions to help quit the program, display the options menu,
and print the sizes of the structures.

The patient.c file contains functions related to the patients structures. This includes printing a patients data, printing
all patients data, and printing a summary of all patients.

The employee.c file contains functions related to the employee structure. This includes printing an employee data, printing
all employees data, and printing a summary of all employees.

The populateRecords.c file contains functions reguarding populating the person, employee and patient structres.

The struct.h file contains the definitions of 2 structures, 1 union, and the limits to the respective attributes. The structures
are Patient, and Employee. The union is a Person which can be either a Patient or Employee.



Issues/Limitations: The maximum number of people to populate is 20 i.e when executing the program, the integer must be between 1 and 20



Revision:
a. 04/11/2021, Jason Huynh - edit/revision
