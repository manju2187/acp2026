/*(a)	Write a C program to check if the electricity units consumed exceed 100 using functions and structure. If they do,
 apply an extra charge of ₹5 per unit over 100 and display a warning message “High consumption alert! Extra charge applied”.
  (if statement)
typedef struct {
int units;
    	float rate;
    	float total_bill;
} ElectricityBill;
Function Prototypes:
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);
(b)	Write a C program to check if the user qualifies for a free unit consumption scheme using functions and structure.
 Example: If consumption is less than 50 units, the bill is ₹0. (if statement)
typedef struct {
    	int units;
    	float rate;
    	float total_bill;
} ElectricityBill;
Function Prototypes:
ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);
*/

#include<stdio.h>

typedef struct{
	int units;
	float rate;
	float total_bill;
}elec_bill;

int extc=5;

elec_bill input(){
	elec_bill e;
	printf("enter the units consumed by the user");
	scanf("%d",&e.units);
	printf("enter the rate per unit of electricity");
	scanf("%f",&e.rate);

	return e;
}

elec_bill calc_bill(elec_bill bill){
	if (bill.units<=100){
		bill.total_bill = bill.units*bill.rate;
	}
	else{
		bill.total_bill = (100 * bill.rate) + ((bill.units-100)*(bill.rate+extc));
	}
	return bill;
}

void output(elec_bill bill){
	printf("the total bill is to be %.2f", bill.total_bill);
}

int main()
{
	int units;
	float rate, total_bill;
	elec_bill bill;
	
	bill=input();
    bill = calc_bill(bill);
	output(bill);
}