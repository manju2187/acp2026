/* Write a program to swap two integer arrays.  
Function prototype:
void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);
*/

#include<stdio.h>

void read_Array(int n, int arr[]){
    int i;
  

    for(i=0;i<n;i++){
        printf("enter the element at array index %d", i);
        scanf("%d", &arr[i]);
    }
}

void print_Array(int n, int arr[]){
    int i;
   
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

void swap_Array(int n, int a[n], int b[n]){
    int i;
    int temp;

    for(i=0;i<n;i++){
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

int main()
{
    int i,n;

    printf("\n enter the size of the arrays \n ");
    scanf("%d", &n);

    int a[i], b[i];

    printf("\t \n enter the first array elements \n");
    read_Array(n,a);

    printf("\t \n enter the second array elements \n");
    read_Array(n,b);

    printf("\n before swapping \n");

    printf("\n array A \n ");
    print_Array(n,a);
    printf(" \n array B \n ");
    print_Array(n,b);

    swap_Array(n,a,b);

    printf("\n after swapping arrays \n");

    printf("\n array A \n ");
    print_Array(n,a);
    printf(" \n array B \n ");
    print_Array(n,b);

    return 0;


}