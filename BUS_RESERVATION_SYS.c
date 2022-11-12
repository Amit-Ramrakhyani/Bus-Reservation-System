#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

char tickets[5][20][20];
char yesNo;
int i, j, k;
int key = 0;

struct Buses{
    int busID;
    char busName[20];
    char source[20];
    char destination[20];
    int date;
    char seats[20][10];
} bus[8];


void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while(clock() < start_time + milli_seconds);
}

void lines() {
    for(j = 0; j < 2; j++) {
        for(i = 0; i < 58; i++) {
            printf("_");
        }
        printf("\n");
    }
}

void menu() {
    lines();
    printf("\n\t\tBUS RESERVATION SYSTEM\n");
    lines();
    
    printf("  \n\t\t     MAIN MENU\n");
    lines();
    printf("\n   [1] VIEW BUS LIST\n\n");
    printf("   [2] BOOK TICKETS\n\n");
    printf("   [3] CANCEL BOOKING\n\n");
    printf("   [4] BUS STATUS BOARD\n\n");
    printf("   [5] EXIT\n");
    lines();
}

void busList() {
    key = 0;
    int dd;
    char src[20];
    char des[20];
    lines();
    printf("\n\t\t      BUS RESERVATION\n");
    lines();
    printf("\nENTER SOURCE : ");
    scanf("%s", src);
    printf("\nENTER DESTINATION : ");
    scanf("%s", des);
    printf("\nENTER DATE (in ddmmyyyy) : ");
    scanf("%d", &dd);
    lines();
    printf("\n\t\t\tAVAILABLE BUSES\n\n");
    lines();
    printf("ID\t\t\tNAME\t\t\tSOURCE\t\t\tDESTINATION\t\t\tDATE\n\n");
    for(i=0; i<8; i++){
        if((strcmp(bus[i].source, src)==0) && (strcmp(bus[i].destination, des)==0) && (bus[i].date == dd)){
            key=1;
            printf("%d\t\t\t%s\t\t%s\t\t\t%s\t\t\t\t%d\n\n", bus[i].busID, bus[i].busName, bus[i].source, bus[i].destination, bus[i].date);
        }
    }
    if(key == 0){
        printf("-\t\t\tNONE\t\t\tNONE\t\t\tNONE\t\t\t\t------\n\n");
    }
}

void status(int busNo) {
    lines();
    printf("\n");
    for(k = 1; k <= 4; k++) {
        for(j = 5*(k-1); j < 5*k; j++) {
            printf("%d. %s\t\t", j+1, bus[busNo-1].seats[j]);
        }
        printf("\n");
    }
    lines();
}

void bookTickets() {
    int totalTickets;
    int busNo;
    int seatno;
    char name[20];
    lines();
    printf("\n\t\t\tBUS RESERVATION\n");
    lines();
    printf("\n\nENTER THE BUS NUMBER : ");
    scanf("%d", &busNo);
    printf("\n\t\tAVAILABLE TICKETS\n\n");
    status(busNo);
    printf("\nENTER THE NUMBER OF TICKETS : ");
    scanf("%d", &totalTickets);
    printf("\n");
    for(i = 0; i < totalTickets; i++){     
        printf("\nENTER THE SEAT NUMBER : ");
        scanf("%d", &seatno);
        printf("ENTER NAME : ");
        scanf("%s", name);
        
        if(!strcmp("Empty", bus[busNo-1].seats[seatno-1])) {
            strcpy(bus[busNo-1].seats[seatno-1], name);
            printf("Seat booked successfully!\n");
        }
        else {
            printf("Seat already filled!\n\n");
            totalTickets++;
        }
    }
}

int cancelTickets() {
    int seatno;
    int busid;
    char ch;
    key = 0;
    lines();
    printf("\n\t\tBUS RESERVATION\n");
    lines();
    printf("\n\nENTER THE BUS ID : ");
    scanf("%d", &busid);

    lines();
    printf("\n\t\t\tBUSES\n\n");
    lines();
    printf("ID\t\t\tNAME\t\t\tSOURCE\t\t\tDESTINATION\t\t\tDATE\n\n");
    for(int i=0; i<8; i++){
        if(bus[i].busID == busid){
            key=1;
            printf("%d\t\t\t%s\t\t%s\t\t\t%s\t\t\t\t%d\n\n", bus[i].busID, bus[i].busName, bus[i].source, bus[i].destination, bus[i].date);
        }
    }
    if(key == 0){
        printf("-\t\t\tNONE\t\t\tNONE\t\t\tNONE\t\t\t\t------\n\n");
    }

    if(key == 0){
        return 0;            
    }

    status(busid);

    printf("\nENTER THE SEAT NUMBER : ");
    scanf("%d", &seatno);

    if(!strcmp("Empty", bus[busid-1].seats[seatno-1])) {
        printf("\nThis seat is already empty.\n");
    }
    else {
        strcpy(bus[busid-1].seats[seatno-1], "Empty");
        printf("\nTicket cancelled successfully!\n");
    }
}

void initialize() {
    bus[0].busID = 1; strcpy(bus[0].busName, "Jagdish Travels"); strcpy(bus[0].source, "Ahmedabad"); strcpy(bus[0].destination, "Vadodara"); bus[0].date = 27032023;
    bus[1].busID = 2; strcpy(bus[1].busName, "Raj Express"); strcpy(bus[1].source, "Mumbai"); strcpy(bus[1].destination, "Ahmedabad"); bus[1].date = 12122022;
    bus[2].busID = 3; strcpy(bus[2].busName, "GreenLine Travels"); strcpy(bus[2].source, "Hyderabad"); strcpy(bus[2].destination, "Bangalore"); bus[2].date = 31052023;
    bus[3].busID = 4; strcpy(bus[3].busName, "Thomas Travels"); strcpy(bus[3].source, "Bhopal"); strcpy(bus[3].destination, "Jaipur"); bus[3].date = 11062022;
    bus[4].busID = 5; strcpy(bus[4].busName, "Patel Travels"); strcpy(bus[4].source, "Surat"); strcpy(bus[4].destination, "Rajkot"); bus[4].date = 30112022;
    bus[5].busID = 6; strcpy(bus[5].busName, "Hardeep Travels"); strcpy(bus[5].source, "Ahmedabad"); strcpy(bus[5].destination, "Vadodara"); bus[5].date = 27032023;
    bus[6].busID = 7; strcpy(bus[6].busName, "GreenLine Travels"); strcpy(bus[6].source, "Bhopal"); strcpy(bus[6].destination, "Jaipur"); bus[6].date = 11062022;
    bus[7].busID = 8; strcpy(bus[7].busName, "Raj Express"); strcpy(bus[7].source, "Surat"); strcpy(bus[7].destination, "Rajkot"); bus[7].date = 30112022;
    
    for(k = 0; k < 8; k++) {
        for(j = 0; j < 20; j++) {
            strcpy(bus[k].seats[j], "Empty");
        }
    }
}

int login() {
	int a=0, i=0, ch;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    
    do {
        system("cls");
        lines();
        printf("\n\t\tBUS RESERVATION SYSTEM\n");
        lines();
        printf("\n\t\t     LOGIN PORTAL\n");
        lines();
        printf("\nENTER USERNAME : ");
        scanf("%s", &uname);
        printf("\nENTER PASSWORD : ");
        while(i < 10) { 
            pword[i] = getch();
            c = pword[i];
            if(c == 13) {
				break;
		    }
            else {
				printf("*");
			}
            i++;
        }
        pword[i]='\0';
		//Last character pword[10] == NULL to end string  
        i = 0;
        printf("\n");
        if((strcmp(uname, "user") == 0) && (strcmp(pword, "pass") == 0)) {
            a = 0;
			lines();
            printf("\n\n\t\t    WELCOME USER !!!");
            printf("\n\n\n\t       Press any key to continue...");
            getch();
            return 0;
            break;
        }
        else {
            lines();
            a++;
            if(a == 3) break;
            printf("\n\nLOGIN IS UNSUCCESSFUL... Press any Key to RETRY");
            getch(); //Helps to hold the Screen till Key Press
        }
    }while(a <= 2);

	if(a == 3) {
        printf("\n\nSorry you have entered the wrong username and password for three times!!");
        delay(2);
        for(int m=0; m<5; m++) {
            system("cls");
            printf("\n\nPlease Wait... %d Seconds", m+1);
            delay(1);
        }
        printf("\nPress any Key to Continue");
		//Calls the delay() function which puts process to sleep for specified Time
		getch();
		//Holds The Screen till Key Press
        login();
        //Recursively calls the login() function till Successful Login
	}
	system("cls");
}

int main() {
    
    int num, i, choice, k = 0;
    char ch;
    int BusNo;
    int x = login();
    if(x == 0) {
        initialize();
        do {
            system("cls");
            menu();
            if(k==0) {
                k=1;
            }
            printf("  \n ENTER YOUR CHOICE: ");
            scanf("%d", &choice);
            system("cls");
            switch(choice) {
                case 1:
                    busList();
                    printf("\nPress any key to CONTINUE");
                    scanf("%c", &ch);
                    break;
                case 2:
                    busList();
                    if(key == 0){
                        printf("\nPress any key to CONTINUE");
                        scanf("%c", &ch);
                        break;
                    }
                    bookTickets();
                    printf("\nPress any key to CONTINUE");
                    scanf("%c", &ch);
                    break;
                case 3:
                    cancelTickets();
                    printf("\nPress any key to CONTINUE");
                    scanf("%c", &ch);
                    break;
                case 4:
                    busList();
                    lines();
                    printf("\nENTER THE BUS ID : ");
                    scanf("%d", &BusNo);
                    lines();
                    printf("\n\t\t\tSTATUS\n\n");
                    status(BusNo);
                    printf("\nPress any key to CONTINUE");
                    scanf("%c", &ch);
                    break;
            }
            scanf("%c", &ch);
        }while(choice != 5);
    }
    
    return 0;
}