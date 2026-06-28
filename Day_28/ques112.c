//Ques 112:Write a program to Create contact management system.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.bin"

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} 
Contact;

void addContact();
void listContacts();
void searchContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("    CONTACT MANAGEMENT SYSTEM    \n");
        printf("==================================\n");
        printf("1. Add New Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); 

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    FILE *file = fopen(FILE_NAME, "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Contact newContact;

    printf("\nEnter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; 

    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email Address: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);

    printf("\nContact successfully saved!\n");
}

void listContacts() {
    FILE *file = fopen(FILE_NAME, "rb"); 
    if (file == NULL) {
        printf("\nNo contacts found! Add a contact first.\n");
        return;
    }

    Contact c;
    int count = 1;

    printf("\n-------------------------------------------------------------\n");
    printf("%-5s %-20s %-15s %-20s\n", "S.No", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");

    while (fread(&c, sizeof(Contact), 1, file)) {
        printf("%-5d %-20s %-15s %-20s\n", count++, c.name, c.phone, c.email);
    }
    
    printf("-------------------------------------------------------------\n");
    fclose(file);
}

void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts found!\n");
        return;
    }

    char searchName[50];
    Contact c;
    int found = 0;

    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcmp(c.name, searchName) == 0) {
            if (!found) {
                printf("\nContact Found:\n");
                printf("----------------------------------------\n");
            }
            printf("Name  : %s\n", c.name);
            printf("Phone : %s\n", c.phone);
            printf("Email : %s\n", c.email);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo contact found with the name '%s'.\n", searchName);
    }

    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\nNo contacts found!\n");
        return;
    }

    FILE *tempFile = fopen("temp.bin", "wb");
    if (tempFile == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char targetName[50];
    Contact c;
    int found = 0;

    printf("\nEnter the name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcmp(c.name, targetName) == 0) {
        } else {
            fwrite(&c, sizeof(Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);           
        rename("temp.bin", FILE_NAME); 
        printf("\nContact '%s' successfully deleted.\n", targetName);
    } else {
        printf("\nContact '%s' not found.\n", targetName);
    }
}

void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}