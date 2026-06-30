//Ques 120:Write a program to Develop complete mini project using arrays, strings and functions. 
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

char names[MAX_CONTACTS][NAME_LEN];
char phones[MAX_CONTACTS][PHONE_LEN];
int contact_count = 0;

void displayMenu();
void addContact();
void viewContacts();
void searchContact();
void deleteContact();

int main() {
    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("\nExiting Contact Management System. Goodbye!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=================================");
    printf("\n   CONTACT MANAGEMENT SYSTEM   ");
    printf("\n=================================");
    printf("\n1. Add New Contact");
    printf("\n2. View All Contacts");
    printf("\n3. Search Contact");
    printf("\n4. Delete Contact");
    printf("\n5. Exit");
    printf("\n=================================");
}

void addContact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("\nPhonebook is full! Cannot add more contacts.\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf(" %[^\n]s", names[contact_count]); 
    
    printf("Enter Phone Number: ");
    scanf("%s", phones[contact_count]);

    contact_count++;
    printf("\nContact added successfully!\n");
}

void viewContacts() {
    if (contact_count == 0) {
        printf("\nNo contacts found. Phonebook is empty.\n");
        return;
    }

    printf("\n--- LIST OF CONTACTS ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. Name: %s | Phone: %s\n", i + 1, names[i], phones[i]);
    }
}

void searchContact() {
    if (contact_count == 0) {
        printf("\nPhonebook is empty. Nothing to search.\n");
        return;
    }

    char search_name[NAME_LEN];
    printf("\nEnter name to search: ");
    scanf(" %[^\n]s", search_name);

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(names[i], search_name) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s | Phone: %s\n", names[i], phones[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact '%s' not found.\n", search_name);
    }
}

void deleteContact() {
    if (contact_count == 0) {
        printf("\nPhonebook is empty. Nothing to delete.\n");
        return;
    }

    char delete_name[NAME_LEN];
    printf("\nEnter name to delete: ");
    scanf(" %[^\n]s", delete_name);

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcasecmp(names[i], delete_name) == 0) {
            for (int j = i; j < contact_count - 1; j++) {
                strcpy(names[j], names[j + 1]);
                strcpy(phones[j], phones[j + 1]);
            }
            contact_count--;
            printf("\nContact '%s' deleted successfully!\n", delete_name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact '%s' not found.\n", delete_name);
    }
}