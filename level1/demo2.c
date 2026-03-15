/*Write a C program to compare areas of three rectangles and find the largest using
 functions and structure. (else-if ladder)
typedef struct {
    	char name[50];
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
Rectangle input();
float calculate_area(Rectangle rect);
void compare_areas(Rectangle r1, Rectangle r2, Rectangle r3);*/

#include<stdio.h>

typedef struct {
    char name[50];
    float length;
    float width;
    float area;
} rectangle;

rectangle input(){
    rectangle r;

    printf("enter the name of the rectangle");
    scanf("%s", r.name);
    printf("enter the length of the rectangle");
    scanf("%f", &r.length);
    printf("enter tghe width of the rectangle");
    scanf("%f", &r.width);

    return r;
}

float calculate_area(rectangle rect){
    float area;
    area = rect.length * rect.width;
    return area;
}

void compare_areas(rectangle r1, rectangle r2, rectangle r3){
    if(r1.area>r2.area && r1.area>r3.area){
        printf("largest rectangle is %s and its area is %.2f", r1.name, r1.area);
    }
    else if(r2.area>r1.area && r2.area>r3.area){
        printf("largest rectangle is %s and its area is %.2f", r2.name, r2.area);
    }
    else{
        printf("largest rectangle is %s and its area is %.2f", r3.name, r3.area);
    }
}

int main()
{
    rectangle r1, r2, r3;

    printf(" \n enter the dimensions of rectanglw 1 \n");
    r1 = input();
    r1.area = calculate_area(r1);

    printf("\n enter the dimensions of rectangle 2 \n");
    r2 = input();
    r2.area = calculate_area(r2);

    printf("\n enter the dimensions of rectangle 3 \n");
    r3 = input();
    r3.area = calculate_area(r3);

    compare_areas(r1,r2,r3);

    return 0;

}