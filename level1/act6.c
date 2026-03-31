/*The sports department requires a digital system to track player 
performance for various matches where the team size varies dynamically.
 Design and implement a modular C program that utilizes Dynamic Memory 
 Allocation to manage these scores efficiently. The program must demonstrate 
 clean coding principles by separating concerns into independent functions
  for memory reservation, data entry, mathematical processing, and output 
  display. Specifically, the system must prompt the user for the number of 
  players, allocate the exact required memory, validate the allocation,
   read the scores, display the scores, compute the total team score, and 
   finally implement a safe deallocation strategy that prevents dangling
    pointers by resetting the memory address to NULL after freeing.
Function Prototypes:
int* allocate_scores(int n);
void read_scores(int *arr, int n);
int calculate_total(int *arr, int n);
void display_scores(int *arr, int n);
void delete_scores(int **arr);*/

#include<stdio.h>
#include<stdlib.h>

int* allocate_scores(int n){
    int *arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }

    return arr;
}

void read_scores(int *arr, int n){
    int i;
    printf("enter scores:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int calculate_total(int *arr, int n){
    int i, sum = 0;
    for(i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

void display_scores(int *arr, int n){
    int i;
    printf("scores are:\n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_scores(int **arr){
    free(*arr);
    *arr = NULL;
}

int main(){
    int n;
    int *scores;
    int total;

    printf("enter number of players:\n");
    scanf("%d",&n);

    scores = allocate_scores(n);

    if(scores == NULL){
        return 0;
    }

    read_scores(scores, n);

    display_scores(scores, n);

    total = calculate_total(scores, n);

    printf("total score is %d\n", total);

    delete_scores(&scores);

    return 0;
}