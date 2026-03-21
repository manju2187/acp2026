/*Write a modular C program to perform the following tasks using file handling functions:
i.Read the details of n students from the user and store them in an array of structures.
ii.Write the array of structures to a text (ASCII) file using fprintf().
iii.Read the data back from the ASCII file into a second array using fscanf() and display it.
iv.Display the array of structures.
Function prototype:
void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);*/

#include<stdio.h>

typedef struct{
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int n;  

void inputStudents(Student students[], int n){
    int i;
    printf("Enter student details\n");
    for(i=0;i<n;i++){
        printf("Student %d:\n",i+1);
        scanf("%d %s %f",&students[i].id,students[i].name,&students[i].marks);
    }
}

void writeToTextFile(Student students[], int n, const char *filename){
    FILE *fp = fopen(filename,"w");

    int i;
    for(i=0;i<n;i++){
        fprintf(fp,"%d %s %f\n",
                students[i].id,
                students[i].name,
                students[i].marks);
    }

    fclose(fp);
}

int readFromTextFile(Student students[], const char *filename){
    FILE *fp = fopen(filename,"r");

    int i;
    for(i=0;i<n;i++){
        fscanf(fp,"%d %s %f",
               &students[i].id,
               students[i].name,
               &students[i].marks);
    }

    fclose(fp);
    return n;
}

void printStudents(Student students[], int n){
    int i;
    printf("\nStudent data:\n");
    for(i=0;i<n;i++){
        printf("%d %s %.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}

int main(){
    printf("Enter number of students:\n");
    scanf("%d",&n);

    Student s1[100], s2[100];

    inputStudents(s1,n);
    writeToTextFile(s1,n,"students.txt");

    int count = readFromTextFile(s2,"students.txt");

    printStudents(s2,count);

    return 0;
}