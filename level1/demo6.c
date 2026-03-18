/*Develop a modular C program to manage an integer array using dynamic memory allocation. You must implement specific functions to allocate, initialize, display, and safely deallocate memory. This task ensures proficiency in preventing memory leaks and managing dangling pointers.
Function prototype:
int* create_array(int n); 
void initialize_array(int *arr, int n); 
void print_array(int *arr, int n); 
void delete_array(int **arr);*/


#include<stdio.h>
#include<stdlib.h>

int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int* create_array(int n){
    int *arr;
    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("memory alocation failed\n");
        return NULL;
    }

    return arr;
}

void initialize_array(int *arr, int n){
    int i;
    printf("enter elemnts of array\n");

    for(i = 0; i < n; i++){
        printf("enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void print_array(int *arr, int n){
    int i;
    printf("array is:\n");

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_array(int **arr){
    free(*arr);
    *arr = NULL;
    printf("memory freed\n");
}

int main(){
    int n;
    int *arr;

    printf("enter size of array: ");
    scanf("%d", &n);

    arr = create_array(n);

    if(arr == NULL){
        return 1;
    }

    initialize_array(arr, n);
    print_array(arr, n);

    delete_array(&arr);

    if(arr == NULL){
        printf("pointer is now NULL\n");
    }

    return 0;
}