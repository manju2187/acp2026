/*Write a C program using functions to read the temperature of each day for a week (7 float values), store them in an array, and 
find the minimum and maximum temperature. (array, passing arrays to functions, for loop, if statement)
Function Prototypes:
void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);
*/

#include<stdio.h>

void inputTemperatures(int n, float temps[n]){
    int i;
    for(i=0;i<n;i++){
        printf("enter the value of temperature on day %d",i+1);
        scanf("%f", &temps[i]);
    }

}

float findHighest(int n, float temps[n]){
    int i;
    float max=temps[0];
    for(i=1;i<n;i++){
        if(temps[i]>max){
            max=temps[i];
        }
    }

    return max;

}

float findLowest(int n, float temps[n]){
    int i;
    float min=temps[0];
    for(i=0;i<n;i++){
        if(temps[i]<min){
            min=temps[i];
        }
    }

    return min;
}

void output(float max, float min){
    printf("the macimum temperature was %.2f and the lowest temperature was %.2f", max, min);
}

int main()
{
    int i,n=7;
    float max,min,temps[n];

    inputTemperatures(n,temps);
    max  = findHighest(n,temps);
    min = findLowest(n,temps);
    output(max,min);

    return 0;



}