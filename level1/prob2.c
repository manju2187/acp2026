/*Write a C program to compare the cost of tiling three floors and determine the
 most expensive one using functions and structure. (else-if ladder)
typedef struct { 
char name[50]; 
float length; 
float width; 
float cost_per_unit; 
float total_cost; 
} Floor;
Function Prototypes:
Floor input();
float calculate_cost(Floor floor);
void compare_costs(Floor f1, Floor f2, Floor f3);*/

#include<stdio.h>

typedef struct{
    char name[10];
    float length;
    float width;
    float cost_per_unit;
    float total_cost;
}Floor;

Floor input(){
    Floor f;
    printf("enter the name ");
    scanf("%s",f.name);

    printf("enter the length");
    scanf("%f",&f.length);

    printf("enter the width");
    scanf("%f",&f.width);

    printf("enter cost per unit");
    scanf("%f",&f.cost_per_unit);

    return f;
}

float calculate_cost(Floor floor){
    
    return floor.length*floor.width*floor.cost_per_unit;
    
}

void compare_cost(Floor f1, Floor f2, Floor f3){
    if(f1.total_cost>f2.total_cost && f1.total_cost>f3.total_cost){
        printf("floor 1 is most expensive");
    }
    else if(f2.total_cost>f1.total_cost && f2.total_cost>f3.total_cost){
        printf("floor 2 has the most expense");
    }
    else if(f3.total_cost>f2.total_cost && f3.total_cost>f1.total_cost){
        printf("floor 3 is the most expensive");
    }
    else if(f1.total_cost==f2.total_cost && f1.total_cost>f3.total_cost){
        printf("loor 1 and 2 have equal cost and most expensive");
    }
    else if(f1.total_cost==f3.total_cost && f1.total_cost>f2.total_cost){
        printf("floor 1 and 3 have the highest cost");
    }
    else if (f2.total_cost==f3.total_cost && f2.total_cost>f1.total_cost){
        printf("floor 2 and 3 have the highest cost");
    }
    else{
        printf("all equal costs");
    }
}

int main()
{
    Floor f1,f2,f3;
    float f,g,h;

    printf("enter the details of floor 1\n");
    f1 =  input();
    f1.total_cost=calculate_cost(f1);   

    printf("enter the details of floor 2\n");
    f2 = input();
    f2.total_cost=calculate_cost(f2);

    printf("enter the details of floor 3\n");
    f3=input();
    f3.total_cost=calculate_cost(f3);

    compare_cost(f1,f2,f3);

    return 0;

}