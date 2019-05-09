#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
 int id;
 char name[50];
 char lastName[50];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#endif // BIBLIOTECA_H_INCLUDED
Employee Employeeadd();
int isEmpty(Employee [], int);
void initEmployees(Employee [], int);
int addemployees(Employee [], int);
void modifyEmployee(Employee[],int);
int removeEmployee(Employee[],int);
void printEmployees(Employee);
void isEmptyEmployeed(Employee[], int);
void sortemployeeBylastN(Employee[],int);
