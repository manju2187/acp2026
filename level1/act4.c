/*Develop a modular C program to manage a team of 11 cricket players and calculate the average runs of the team. Create a 
structure Player with the following members:
•	player_name
•	jersey_number
•	runs_scored
Create an array of 11 players. Write a program that:
1.	Reads the details of all 11 players.
2.	Calculates and displays the average runs scored by the team.
Function prototype:
void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);
*/

#include<stdio.h>

typedef struct{
    char player_name[100];
    int jersey_number;
    int runs_scored;
}Player;

void read_Players(int n, Player p[]){
    for(int i=0;i<n;i++){
        printf("enter the player name of %d player",i+1);
        scanf("%s", p[i].player_name);
        printf("enter the jersey number of %d player",i+1);
        scanf("%d", &p[i].jersey_number);
        printf("enter the runs scored by the %d player",i+1);
        scanf("%d",&p[i].runs_scored);
    }
}

float calculate_avg(int n, Player p[]){
    int avg;
    int total=0;
    for(int i=0;i<n;i++){
        total=total+p[i].runs_scored;
    }
    avg=total/n;

    return avg;
}

int main()
{
    int n;
    n=11;
    Player p[100];
    float avg;

    read_Players(n, p);
    avg=calculate_avg(n,p);

    printf("the avergae runs scored by the team is %f",avg);
}