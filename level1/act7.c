/*Write a C program using user-defined functions to
i.	Accept names of two students.
ii.	Find the length of each student's name.
iii.	Compare which student's name is longer and display an appropriate message. (strings, while/do while, if)
Function Prototypes:
void input(char *name);
int calculate_name_length(char *name);
void compare_output(int len1, int len2);
*/

#include<stdio.h>
#include<string.h>

void input(char *name){
    printf("enter the name of student \n");
    scanf("%s", name);
}

int calculate_name_length(char *name){
    return strlen(name);
}

void compare_output(int len1, int len2){

    if(len1>len2){
        printf("student 1 has the longest name among the two \n");
    }

    else if(len2>len1){
        printf("student 2 has the longest name among the two \n");
    }

    else{
        printf("both student names have the same length \n");
    }
}

int main()
{
    int len1, len2;
    char name1[100], name2[100];

    printf("for student 1 \n");
    input(name1);
    len1= calculate_name_length(name1);

    printf("for student 2 \n");
    input(name2);
    len2= calculate_name_length(name2);

    compare_output(len1,len2);

    return 0;
}