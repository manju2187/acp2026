/* Write a C program using array of structures and functions to:
i.Accept the number of rectangles.
ii.For each rectangle, accept its length and width.
iii.Calculate and display the area of each rectangle.
iv.Determine and display the rectangle with the largest area. (array of structures, for loop, if statement)
typedef struct {
    	float length;
    	float width;
    	float area;
} Rectangle;
Function prototype:
void input(int n, Rectangle rects[n]);
void calculate_area(int n, Rectangle rects[n]);
int findLargestArea(int n, Rectangle rects[n]);
void output(int largestIndex, Rectangle rects[]);
*/

#include<stdio.h>

typedef struct {
    float length;
    float width;
    float area;   
} rectangle;

void input(int n, rectangle rects[n]){
    int i;

    for(i=0;i<n;i++){
        printf("enter the length and breadth of rectangle number %d",i);
        scanf("%f %f", &rects[i].length, &rects[i].width);
    }
}

void calculate_area(int n, rectangle rects[n]){
    int i;
    for(i=0;i<n;i++){
        rects[i].area = rects[i].length * rects[i].width;
        printf("\n area of the %d rectangle is %.2f \n", i , rects[i].area );
    }
}

int findlargestArea(int n, rectangle rects[n]){
    int i;
    float temp=0;
    int largestindex=0;
    for(i=1;i<n;i++){
        if(rects[largestindex].area<rects[i].area){
            largestindex = i;
        }
    }

    return largestindex;
}

void output(int largestindex, rectangle rects[]){
    printf("\n the largest rectangle is rectangle number %d and its area is %.2f \n", largestindex, rects[largestindex].area );
}

int main()
{
    rectangle rects[100];
    int n;
    int largestindex;
    printf("enter the number of rectangles");
    scanf("%d", &n);

    input(n, rects );
    calculate_area(n, rects);
    largestindex =  findlargestArea(n, rects);
    output(largestindex,rects);
    

}