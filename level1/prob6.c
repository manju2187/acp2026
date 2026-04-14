/*A pharmacy requires a digital inventory system to track medications and their expiration 
years. Design and implement a modular C program to manage this data using a structure that 
stores a medicine's ID, name, and expiration year. The system must allow the user to define
 the number of medicines to be entered, input the data for each record, and display the complete
  inventory list. To ensure clean coding and professional memory management, the program must use 
  separate functions for memory allocation, data entry, display, and safe deallocation of the array.
Function Prototypes:
Medicine_t* allocate_inventory(int n);
void read_inventory(Medicine_t *m, int n);
void display_inventory(Medicine_t *m, int n);
void delete_inventory(Medicine_t **m);*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    char name[50];
    int expiryYear;
} Medicine_t;

Medicine_t* allocate_inventory(int n){
    Medicine_t *m;
    m = (Medicine_t*)malloc(n * sizeof(Medicine_t));
    return m;
}

void read_inventory(Medicine_t *m, int n){
    for(int i=0;i<n;i++){
        printf("enter id of medicine %d\n", i+1);
        scanf("%d", &m[i].id);

        printf("enter name of medicine %d\n", i+1);
        scanf("%s", m[i].name);

        printf("enter expiry year of medicine %d\n", i+1);
        scanf("%d", &m[i].expiryYear);
    }
}

void display_inventory(Medicine_t *m, int n){
    printf("\nmedicine inventory:\n");
    for(int i=0;i<n;i++){
        printf("ID: %d Name: %s Expiry: %d\n",
               m[i].id,
               m[i].name,
               m[i].expiryYear);
    }
}

void delete_inventory(Medicine_t **m){
    free(*m);
    *m = NULL;
}

int main()
{
    int n;
    Medicine_t *m = NULL;

    printf("enter number of medicines\n");
    scanf("%d", &n);

    m = allocate_inventory(n);

    if(m == NULL){
        printf("memory allocation failed\n");
        return 1;
    }

    read_inventory(m, n);
    display_inventory(m, n);
    delete_inventory(&m);

    return 0;
}