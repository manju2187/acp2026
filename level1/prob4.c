/*Develop a modular C program to manage a fleet of 4 cars. Use a structure to store 
vehicle details and implement logic to display only modern vehicles (manufactured after 2022).
 Create a structure Car with the following members:
car_id
model_name
manufacture_year
price
Create an array of 4 cars. The program should read details of 4 cars from the user. Display 
only those cars manufactured after the year 2022.
Function prototype:
void readCars(int n, Car c[]);
void displayModernCars(int n, Car c[]);*/

#include<stdio.h>

typedef struct{
    int carID;
    char modelName[20];
    int manufacturedYEAR;
    float price;
} Car;

void readCars(int n, Car c[]){
    for(int i = 0; i < n; i++){
        printf("enter the ID of car %d\n", i+1);
        scanf("%d", &c[i].carID);

        printf("enter the model name of car %d\n", i+1);
        scanf("%s", c[i].modelName);

        printf("enter the manufactured year of car %d\n", i+1);
        scanf("%d", &c[i].manufacturedYEAR);

        printf("enter the price of car %d\n", i+1);
        scanf("%f", &c[i].price);
    }
}

void displayModernCars(int n, Car c[]){
    printf("\nModern cars (ater 2022:\n");

    for(int i = 0; i < n; i++){
        if(c[i].manufacturedYEAR > 2022){
            printf("ID: %d, Model: %s, Year: %d, Price: %.2f\n",
                   c[i].carID,
                   c[i].modelName,
                   c[i].manufacturedYEAR,
                   c[i].price);
        }
    }
}

int main()
{
    int n = 4;
    Car c[n];

    readCars(n, c);
    displayModernCars(n, c);

    return 0;
}