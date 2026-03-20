/*Write a C program to concatenate two strings using user-defined functions. The program should 
accept two strings from the user and pass them to a function that performs the concatenation. 
(strings, while/do while)
Function prototype:
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);*/

#include<stdio.h>
#include<string.h>

void input(char *str){
    scanf("%s", str);
}

void concatenate(char *str1, char *str2){
    strcat(str1,str2);
}

void display(char *str){
    printf("the string after concatenation is %s ", str);
}

int main()
{
    char str1[50], str2[50];

    printf("enter the first string ");
    input(str1);

    printf("enter the second string");
    input(str2);

    printf("the strong after concatenation is %s", str1);
}
