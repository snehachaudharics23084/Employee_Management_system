9#include <stdio.h>
#include <stdlib.h>
struct employee {
  char name[50];
  int emp_id;
  int age;
  char designation[30];
  float salary;
};

struct employee employees[100];
int numEmployees = 0;

void addEmployee() { 
  struct employee newEmployee;
  int n,i;
  printf("enter no. of employee to be added:");
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
  
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.emp_id);
  
    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);

    printf("Enter employee Designation: ");
    scanf("%s", newEmployee.designation);
  
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    
    employees[numEmployees++] = newEmployee;
  }
}

void listEmployees() {
     int i;
  if (numEmployees == 0) {
    printf("No employees added yet.\n");
    return;
  }
  for (i = 0; i < numEmployees; i++) {
    printf("Employee %d:\n", i + 1);
    printf("Name: %s\n", employees[i].name);
    printf("Id: %d\n", employees[i].emp_id);
    printf("Age: %d\n", employees[i].age);
    printf("Designation:%s\n",employees[i].designation);
    printf("Salary: %.2f\n", employees[i].salary);
    printf("\n");
  }
}

void searchEmployee() {
  int id,i;

  printf("Enter employee id: ");
  scanf("%d", &id);

  for (i = 0; i < numEmployees; i++) {
    if (employees[i].emp_id == id) {
      printf("Employee found:\n");
      printf("Name: %s\n", employees[i].name);
      printf("Id: %d\n", employees[i].emp_id);
      printf("Age: %d\n", employees[i].age);
      printf("Designation:%s\n",employees[i].designation);
      printf("Salary: %.2f\n", employees[i].salary);
      return;
    }
  }

  printf("Employee not found.\n");
}

void updateEmployee() {
  int id;
  printf("Enter employee id: ");
  scanf("%d", &id);
  int i;
  for (i = 0; i < numEmployees; i++) {
    if (employees[i].emp_id == id) {
      printf("Enter employee name: ");
      scanf("%s", employees[i].name);
  
      printf("Enter employee ID: ");
      scanf("%d", &employees[i].emp_id);
  
      printf("Enter employee age: ");
      scanf("%d", &employees[i].age);

      printf("Enter employee Designation: ");
      scanf("%s", employees[i].designation);
  
      printf("Enter employee salary: ");
      scanf("%f", &employees[i].salary);
      printf("Employee updated successfully.\n");
      return;
    }
  }

  printf("Employee not found.\n");
}

void deleteEmployee() {
  int id,i,j;

  printf("Enter employee id: ");
  scanf("%d", &id);

  for (i = 0; i < numEmployees; i++) {
    if (employees[i].emp_id == id) {
      for (j = i; j < numEmployees - 1; j++) {
        employees[j] = employees[j + 1];
      }

      numEmployees--;
      printf("Employee deleted successfully.\n");
      return;
    }
  }

  printf("Employee not found.\n");
}

int main() {
  int choice;

  while (1) {
    printf("Employee Management System\n");
    printf("1. Add employee\n");
    printf("2. List employees\n");
    printf("3. Search employee\n");
    printf("4. Update employee\n");
    printf("5. Delete employee\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEmployee();
        break;
      case 2:
        listEmployees();
        break;
      case 3: 
        searchEmployee();
        break;
      case 4:
        updateEmployee();
        break;
      case 5:
        deleteEmployee();
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
