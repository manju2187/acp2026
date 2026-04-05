/*A startup needs a system to manage employee salaries and persist them for monthly auditing.
 Develop a modular C program to store employee records (ID, Name, and Basic Salary) in an array 
 of structures. The program should write these records to a text file named payroll.txt. 
 Subsequently, it should read the data from the file to calculate the total salary expenditure 
 and display it. 
Function Prototypes:
void inputEmployees(Employee e[], int n);
void writeToTextFile(Employee e[], int n, const char *filename);
float calculateTotalPayroll(const char *filename);
void displayExpenditure(float total);*/

#include<stdio.h>

typedef struct{
    int empID;
    char name[20];
    int basicsalary;
}Employee;

void inputEmployees(Employee e[], int n){
    for(int i=0;i<n;i++){
        printf("enter the ID of employee %d\n",i+1);
        scanf("%d", &e[i].empID);

        printf("enter the name of employee %d\n", i+1);
        scanf("%s", e[i].name);

        printf("enter the basic salary of employee %d\n", i+1);
        scanf("%d", &e[i].basicsalary);
    }
}

void writeToTextFile(Employee e[], int n, const char *filename){
    FILE *fp = fopen(filename,"w");

    if(fp==NULL){
        printf("file error\n");
        return;
    }

    for(int i=0;i<n;i++){
        fprintf(fp,"%d %s %d\n", e[i].empID, e[i].name, e[i].basicsalary);
    }

    fclose(fp);
}

float calculateTotalPayroll(const char *filename){
    FILE *fp = fopen(filename,"r");

    if(fp==NULL){
        printf("file error\n");
        return 0;
    }

    int empID;
    char name[20];
    int basicsalary;
    float total = 0;

    while(fscanf(fp,"%d %s %d", &empID, name, &basicsalary) == 3){
        total += basicsalary;
    }

    fclose(fp);
    return total;
}

void displayExpenditure(float total){
    printf("total salary expenditure = %.2f\n", total);
}

int main()
{
    int n;
    Employee e[100];
    float total;

    printf("enter the number of employees\n");
    scanf("%d", &n);

    inputEmployees(e, n);
    writeToTextFile(e, n, "payroll.txt");

    total = calculateTotalPayroll("payroll.txt");

    displayExpenditure(total);

    return 0;
}