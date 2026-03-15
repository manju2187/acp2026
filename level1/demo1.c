/* Write a modular C program to read n float values
 from the user, store them in an array and find the maximum 
 value and its index. (array, passing arrays to functions, 
 for loop, if statement)
Function prototype:
void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[ ], int max_index);
*/

#include<stdio.h>

void input(int n, float arr[n]){
    int i;
    
    for(i=0;i<n;i++){
        printf("enter the value of element at index %d: ", i);
        scanf("%f", &arr[i]);
    }
}

int find_max_index(int n, float arr[n]){
    int max_index = 0, i;
    float temp=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>temp){
            temp=arr[i];
            max_index=i;
        }
    }
    return max_index;
}

void output(float arr[], int max_index){
    printf("the largest value in array is %.2f at the index %d\n", arr[max_index], max_index);
}

int main()
{
    int n, max_index;

    printf("enter the size of array: ");
    scanf("%d", &n);

    float arr[n];

    input(n, arr);
    max_index = find_max_index(n, arr);
    output(arr, max_index);

    return 0;
}
