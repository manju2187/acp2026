/*Write a modular C program to perform the following tasks using file handling functions:
i.Read the details of n students from the user and store them in an array of structures
ii.Write the array of structures to a binary file using fwrite().
iii.Read the binary file into a second array of structures using fread().
iv.Display the array of structures.
Function prototype:
void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);*/

#include<stdio.h>

typedef struct{
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

void inputStudents(Student students[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("student %d:\n",i+1);
        scanf("%d %s %f",&students[i].id,students[i].name,&students[i].marks);
    }
}

void writeToBinaryFile(Student students[], int n, const char *filename){
    FILE *fp = fopen(filename,"wb");

    if(fp == NULL){
        printf("file error\n");
        return;
    }

    fwrite(students,sizeof(Student),n,fp);

    fclose(fp);
}

int readFromBinaryFile(Student students[], const char *filename){
    FILE *fp = fopen(filename,"rb");

    if(fp == NULL){
        printf("file error\n");
        return 0;
    }

    int count = fread(students,sizeof(Student),100,fp);

    fclose(fp);
    return count;
}

void printStudents(Student students[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d %s %.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}

int main(){
    int n;

    printf("enter number of students:\n");
    scanf("%d",&n);

    Student s1[100], s2[100];

    inputStudents(s1,n);
    writeToBinaryFile(s1,n,"students.dat");

    int count = readFromBinaryFile(s2,"students.dat");

    printStudents(s2,count);

    return 0;
}