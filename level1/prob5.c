/*Write a program to swap two structures.
typedef struct {
    char name[50];
    int age;
} Person;  
Function prototype:
void read_person(Person *p);
void print_person(Person *p);
void swap_person(Person *p1, Person *p2);*/

#include<stdio.h>

typedef struct{
    char name[50];
    int age;
}Person;

void readPerson(Person *p){
    printf("enter the name of the student\n ");
    scanf("%s", p->name);
    printf("enter the age of the student\n ");
    scanf("%d", &p->age);
}

void printPerson(Person *p){
    printf("%s\n",p->name);
    printf("%d\n",p->age);
}

void swapPerson(Person *p1, Person *p2){
    Person temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main()
{
    Person p1, p2;

    printf("enter the details of first student\n");
    readPerson(&p1);

    printf("enter the details of second student\n");
    readPerson(&p2);

    printf("detils of first student are\n");
    printPerson(&p1);

    printf("details of second student are\n");
    printPerson(&p2);

    swapPerson(&p1,&p2);

    printf("details of swapped first student are \n");
    printPerson(&p1);

    printf("details of swapped second student are\n");
    printPerson(&p2);
}