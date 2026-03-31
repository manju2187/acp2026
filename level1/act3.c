/*Write a C program to calculate electricity bills for multiple consumers using array of structures and functions and
 display the highest bill. (array of structures, for loop, if statement)
typedef struct {
    	int consumerID;
    	float unitsConsumed;
    	float billAmount;
} Bill;
Function Prototypes:
void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);
*/

#include<stdio.h>

typedef struct{
    int consumerID;
    float unitsConsumed;
    float billamount;
}bill;

int rate=8;
void input(int n, bill bills[]){
    int i;
    for(i=0;i<n;i++){
        printf("\nenter the consumer ID of %d consumer\n",i+1);
        scanf("%d", &bills[i].consumerID);
        printf("enter the units consumed by the %dth user\n",i+1);
        scanf("%f", &bills[i].unitsConsumed);
    }
}

void calculate_bills(int n, bill bills[n]){
    int i;
    for(i=0;i<n;i++){
        bills[i].billamount = bills[i].unitsConsumed*rate;
    }
}

int findHighestBillIndex(int n, bill bills[n]){
    float hbill=bills[0].billamount;
    int t=0;
    for(int i=1;i<n;i++){
        if(bills[i].billamount>hbill){
            hbill=bills[i].billamount;
            t=i;
        }
    }
    return t;
}

void displayHighestBill(int index, bill bills[]){
    printf("the highest bill is %.2f and is by the user of user id %d \n", bills[index].billamount, bills[index].consumerID );
}

int main()
{
    int n;
    int t;

    printf("enter the number of users \n");
    scanf("%d", &n);

    bill bills[n];

    input(n,bills);
    calculate_bills(n,bills);
    t=findHighestBillIndex(n,bills);
    displayHighestBill(t,bills);

    return 0;
}