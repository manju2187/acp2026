/*Write a C program to count the number of vowels and consonants in
 a given string using a user-defined function. The program should 
 accept a string from the user and pass it to a function that performs
  the counting logic. (strings, while/do while)
Function Prototypes:
void input(char *str);
void count(char *str, int *vowels, int *consonants);
void display(char *str, int vowels, int consonants);*/

#include<stdio.h>

void input(char *str);
void count(char *str, int *vowels, int *consonants);
void display(char *str, int vowels, int consonants);

int main()
{
    char str[100];
    int vowels = 0, consonants = 0;

    input(str);
    count(str, &vowels, &consonants);
    display(str, vowels, consonants);

    return 0;
}

void input(char *str){
    printf("enter a string:\n");
    scanf("%s", str);
}

void count(char *str, int *vowels, int *consonants){
    int i = 0;

    while(str[i] != '\0'){
        char ch = str[i];

        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){

            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
               ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                (*vowels)++;
            }
            else{
                (*consonants)++;
            }
        }

        i++;
    }
}

void display(char *str, int vowels, int consonants){
    printf("string: %s\n", str);
    printf("vowels = %d\n", vowels);
    printf("consonants = %d\n", consonants);
}