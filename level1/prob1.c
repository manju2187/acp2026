/*Write a C program using functions to read the marks (float) obtained by n students 
in a test, store them in an array, and find the highest and lowest mark scored. 
(array, passing arrays to functions, for loop, if statement)
Function Prototypes:
void inputMarks(int n, float marks[n]);
float findHighestMark(int n, float marks[n]);
float findLowestMark(int n, float marks[n]);
void output(float max, float min);*/

#include<stdio.h>

void inputMarks(int n, float marks[n]){
    for(int i=0;i<n;i++){
        printf("enter the marks scored by student %d\n",i+1);
        scanf("%f",&marks[i]);
    }
}

float findHighest(int n, float marks[n]){
    float max=marks[0];

    for(int i=1;i<n;i++){
        if(marks[i]>max){
            max=marks[i];
        }
    }

    return max;
}

float findLowest(int n, float marks[n]){
    float min=marks[0];

    for(int i=1;i<n;i++){
        if(marks[i]<min){
            min=marks[i];
        }
    }

    return min;
}

void output(float max, float min){
    printf("Highest marks = %.2f \nLowest marks = %.2f\n", max, min);
}

int main()
{
    int n;
    printf("enter the number of students");
    scanf("%d", &n);

    float marks[n],max,min;

    inputMarks(n,marks);
    max=findHighest(n,marks);
    min=findLowest(n,marks);
    output(max,min);

    return 0;
}