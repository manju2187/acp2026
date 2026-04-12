/*An airline reservation system requires a high-performance method to archive flight 
details. Unlike text files, binary storage allows the system to save and retrieve complex 
structure data rapidly without data conversion. Develop a modular C program to manage 
flight records (Flight Number, Destination, and Ticket Price). The program must input
 $n$ flights, save the entire array of structures to a binary file named flights.bin
  using block-write operations, and then read the file to find and display the flight
   with the highest ticket price.
Function Prototypes:
void inputFlights(Flight f[], int n);
void saveToBinary(Flight f[], int n, const char *filename);
Flight findMostExpensive(const char *filename);
void displayTopFlight(Flight f);*/

#include<stdio.h>

typedef struct{
   int flight_num;
   char dest[20];
   float ticket_price;

}Flight;

void inputFlights(Flight f[], int n){
   for(int i=0; i<n;i++){
      printf("enter the flight number of flight %d", i+1);
      scanf("%d", &f[i].flight_num);
      printf("etner the destination of flight %d", i+1);
      scanf("%s", f[i].dest);
      printf("enter the ticket price of flight %d",i+1);
      scanf("%f", &f[i].ticket_price);
   }
}

void saveToBinary(Flight f[], int n, const char *filename){
   FILE *fp=fopen (filename,"wb");

   if(fp==NULL){
      printf("invalid flight \n");
      return;
   }

   fwrite(f,sizeof(Flight),n,fp);
   fclose(fp);
}

Flight findMostExpensive(const char *filename){
   Flight max ={0}, temp={0};
   FILE *fp = fopen(filename,"rb");

   if(fp==NULL){
      printf("invalid file \n");
      return max;
   }

   fread(&max,sizeof(Flight),1,fp);

   while(fread(&temp,sizeof(Flight),1,fp)==1){
      if(temp.ticket_price>max.ticket_price){
         max=temp;
      }
   }

   return max;
}

void displayTopFlight(Flight f){
   printf("the most expensive flight and its details is \n");
   printf(" %d %s %.2f", f.flight_num, f.dest, f.ticket_price);
}

int main()
{
   int n;
   Flight f[100], max={0};

   printf("enter the number of flights\n");
   scanf("%d",&n);
   
   inputFlights(f,n);
   saveToBinary(f,n,"flights.bin");
   max = findMostExpensive("flights.bin");
   displayTopFlight(max);

   return 0;
}