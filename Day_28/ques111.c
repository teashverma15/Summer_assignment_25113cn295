//Ques 111:Write a program to Create ticket booking system.
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20
#define TICKET_PRICE 500

typedef struct {
    int seatNumber;
    int isBooked;
    char passengerName[50];
} Seat;

void initializeSeats(Seat seats[]);
void displaySeats(Seat seats[]);
void bookTicket(Seat seats[]);
void cancelTicket(Seat seats[]);

int main() {
    Seat theaterSeats[TOTAL_SEATS];
    int choice;

    initializeSeats(theaterSeats);

    while (1) {
        printf("\n=================================");
        printf("\n   TICKET BOOKING SYSTEM IN C   ");
        printf("\n=================================");
        printf("\n1. View Seat Matrix Status");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Exit Application");
        printf("\n---------------------------------");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data entered. Exiting system.\n");
            break;
        }

        switch (choice) {
            case 1:
                displaySeats(theaterSeats);
                break;
            case 2:
                bookTicket(theaterSeats);
                break;
            case 3:
                cancelTicket(theaterSeats);
                break;
            case 4:
                printf("\nThank you for using our booking system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void initializeSeats(Seat seats[]) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "None");
    }
}

void displaySeats(Seat seats[]) {
    printf("\n--- Theater Seat Matrix Grid ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].isBooked == 0) {
            printf("[%02d: Available]   ", seats[i].seatNumber);
        } else {
            printf("[%02d: BOOKED   ]   ", seats[i].seatNumber);
        }
        
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("--------------------------------\n");
}

void bookTicket(Seat seats[]) {
    int seatNo;
    displaySeats(seats);
    
    printf("\nEnter the seat number you want to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("\nError: Seat number does not exist!\n");
        return;
    }

    int index = seatNo - 1;

    if (seats[index].isBooked == 1) {
        printf("\nError: Seat %d is already taken by %s!\n", seatNo, seats[index].passengerName);
    } else {
        printf("Enter passenger full name: ");
        while (getchar() != '\n'); 
        fgets(seats[index].passengerName, sizeof(seats[index].passengerName), stdin);
        
        seats[index].passengerName[strcspn(seats[index].passengerName, "\n")] = '\0';
        
        seats[index].isBooked = 1;
        
        printf("\n--- Transaction Success Summary ---");
        printf("\nPassenger Name: %s", seats[index].passengerName);
        printf("\nAssigned Seat : %d", seatNo);
        printf("\nTotal Cost    : %d INR", TICKET_PRICE);
        printf("\n-----------------------------------\n");
    }
}

void cancelTicket(Seat seats[]) {
    int seatNo;
    printf("\nEnter your booked seat number for cancellation (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("\nError: Invalid seat number choice.\n");
        return;
    }

    int index = seatNo - 1;

    if (seats[index].isBooked == 0) {
        printf("\nNotice: This seat is not currently booked.\n");
    } else {
        printf("\nBooking for seat %d registered under '%s' has been successfully canceled.\n", 
               seatNo, seats[index].passengerName);
        
        seats[index].isBooked = 0;
        strcpy(seats[index].passengerName, "None");
    }
}