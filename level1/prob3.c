/*Write a C program using functions and array of structures to calculate the tiling 
cost for multiple floors and display the floor that has the highest total tiling cost.
 (array of structures, for loop, if statement)
typedef struct {
    	float length;
    	float width;
    	float area;
    	float costPerUnit;
    	float totalCost;
} Floor;
Function Prototypes:
void inputDetails(int n, Floor floors[n]);
void calculateCosts(int n, Floor floors[n]);
void highestCostFloor(int n, Floor floors[n]);
void displayHighestCost(int index, Floor floors[]);*/

#include<stdio.h>

typedef struct{
    float length;
    float width;
    float area;
    float costPerUnit;
    float totalCost;
}Floor;

void inputDetails(int n, Floor floors[n]){
    for(int i=0;i<n;i++){
        printf("enter the length of %d floor",i);
        scanf("%f",&floors[i].length);

        printf("enter the width of %d floor",i);
        scanf("%f",&floors[i].width);

        printf("enter the cost per unit of the %d floor ",i);
        scanf("%f",&floors[i].costPerUnit);
    }
}   

void calculateCost(int n, Floor floors[n]){
    for(int i=0;i<n;i++){
        floors[i].area=floors[i].length*floors[i].width;
        floors[i].totalCost=floors[i].area*floors[i].costPerUnit;
    }
}

float highestCostFloor(int n, Floor floors[n]){
    int max=0;
    for(int i=1;i<n;i++){
        if(floors[i].totalCost>floors[max].totalCost){
            max=i;
        }
    }
    return max;
}

void displayHighest(int index, Floor floors[]){
    printf("the most expensive floor to lay tiles on was the %d floor which cost %.2f",index,floors[index].totalCost);
}

int main()
{
    int n;
    printf("enter the number of floors ");
    scanf("%d",&n);

    if(n<1){
        printf("invalid number of floors \n");
        return 0;
    }

    Floor floors[n];

    inputDetails(n,floors);
    calculateCost(n,floors);
    int max = highestCostFloor(n,floors);
    displayHighest(max,floors);

    return 0;
}