#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee EmployeeArray[MAX_EMPLOYEES];

	int employeeCounter = 0;
	// ask user for MAX_EMPLOYEES employees
	while (employeeCounter < MAX_EMPLOYEES) {
		printf("Name: ");
		scanf("%s", EmployeeArray[employeeCounter].name);
		printf("Salary: ");
		scanf("%d", &EmployeeArray[employeeCounter].salary);
		employeeCounter++;
	}

	printf("Before HeapSort: ");
	printList(EmployeeArray, MAX_EMPLOYEES);
	heapSort(EmployeeArray, MAX_EMPLOYEES);
	printf("After HeapSort: ");
	printList(EmployeeArray, MAX_EMPLOYEES);
	return 0;
}
