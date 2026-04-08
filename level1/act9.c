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
    int emID;
    char name[20];
    float basesalary;
}Employee;

void input(Employee e[], int n){
    for(int i=0;i<n;i++){
        printf("enter the employee ID of the %d employee",i+1);
        scanf("%d", &e[i].emID);
        printf("enter the employee name of the %d employee", i+1);
        scanf("%s", e[i].name);
        printf("enter the base salary of the %d employee",i+1);
        scanf("%f", &e[i].basesalary);
    }
}

void writetofile(Employee e[], int n, const char *filename){
    FILE *fp = fopen(filename,"w");

    if (fp==NULL){
        printf("empty invalid");
        return ;
    }

    for(int i=0;i<n;i++){
        fprintf(fp,"%d %s %.2f \n",e[i].emID,e[i].name,e[i].basesalary);
    }

    fclose(fp);
}

float calculatePay(const char *filename){
    FILE *fp = fopen(filename,"r");

    if(fp==NULL){
        printf("invalid file");
        return 0;
    }

    int emID;
    char name[20];
    float basicsalary;
    float total;

    while(fscanf(fp,"%d %s %f",&emID, &name, &basicsalary)==3){
        total += basicsalary;
    }
    fclose(fp);
    return total;
}

void display(float total){
    printf("the total salary expenditure is %.2f\n",total);
}

int main()

{
    int n;
    Employee e[100];
    float total;

    printf("enter the number of employees\n");
    scanf("%d", &n);

    input(e,n);
    writetofile(e,n,"payroll.txt");
    total = calculatePay("payroll.txt");
    display(total);

    return 0;
}

