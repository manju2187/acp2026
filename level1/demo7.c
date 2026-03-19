/*The sports department requires a digital system to track player performance for various matches where the team size varies dynamically. Design and implement a modular C program that utilizes Dynamic Memory Allocation to manage these scores efficiently. The program must demonstrate clean coding principles by separating concerns into independent functions for memory reservation, data entry, mathematical processing, and output display. Specifically, the system must prompt the user for the number of players, allocate the exact required memory, validate the allocation, read the scores, display the scores, compute the total team score, and finally implement a safe deallocation strategy that prevents dangling pointers by resetting the memory address to NULL after freeing.
Function Prototypes:
int* allocate_scores(int n);
void read_scores(int *arr, int n);
int calculate_total(int *arr, int n);
void display_scores(int *arr, int n);
void delete_scores(int **arr);
*/







#include<stdio.h>

int main(){
    int arr[100];
    int n,i,total=0;

    printf("enter number of players: ");
    scanf("%d",&n);

    printf("enter scores:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        total = total + arr[i];
    }

    printf("\ntotal is %d",total);

    return 0;
}