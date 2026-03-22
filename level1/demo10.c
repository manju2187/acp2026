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

int main(){
    int n,i;

    printf("enter number of students:\n");
    scanf("%d",&n);

    Student s1[100], s2[100];

    for(i=0;i<n;i++){
        printf("enter id name marks:\n");
        scanf("%d %s %f",&s1[i].id,s1[i].name,&s1[i].marks);
    }

    FILE *fp = fopen("students.dat","wb");

    for(i=0;i<n;i++){
        fwrite(&s1[i],sizeof(Student),1,fp);
    }

    fclose(fp);

    fp = fopen("students.dat","rb");

    for(i=0;i<n;i++){
        fread(&s2[i],sizeof(Student),1,fp);
    }

    fclose(fp);

    for(i=0;i<n;i++){
        printf("%d %s %.2f\n",s2[i].id,s2[i].name,s2[i].marks);
    }

    return 0;
}