/* Write a modular C program to create a structure Flight with
 flight_number, destination, and available_seats. Create an 
 array of 4 flights. Write a program that takes a destination
  name from the user and checks if a flight is available to 
  that location, displaying the flight number if found.
Function prototype:
void readFlights(int n, Flight_t f[]); 
void searchByDestination(int n, Flight_t f[], char searchDest[]);
*/

#include<stdio.h>
#include<string.h>

typedef struct{
    int flight_num;
    char destination[100];
    int available_seats;
} flight;

void readFlights(int n, flight f[]){
    int i;
    printf("\n \t enter the flight details \n");

    for(i=0;i<n;i++){
        printf("\n enter the flight number of %d plane \n", i);
        scanf("%d", &f[i].flight_num);
        printf("\n enter the destination name of %d plane \n",i);
        scanf("%s", f[i].destination);
        printf("\n enter the number of seats available for %d plane \n", i);
        scanf("%d", &f[i].available_seats);
    }
}

void searchByDestination(int n, flight f[], char searchDest[]){
    int i;
    int found = 0;

    printf("\n \t enter your destination \n ");
    scanf("%s", searchDest);

    for(i = 0; i < n; i++){
        if(strcmp(searchDest, f[i].destination) == 0){
            printf("\n plnae number %d is available with %d seats\n",f[i].flight_num,f[i].available_seats);
            found = 1;
        }
    }

    if(found == 0){
        printf("\n the destination entered does not have any flights \n");
    }
}

int main()
{
    int n=4;
    flight f[n];
    char searchDest[10];

    readFlights(n,f);
    searchByDestination(n,f,searchDest);

    return 0;
}