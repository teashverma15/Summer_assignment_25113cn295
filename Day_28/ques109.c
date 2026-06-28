//Ques 109:Write a program to Create library management system. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid menu input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting system... Thank you!\n");
                exit(0);
            default:
                printf("\n[Error] Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\n[Error] Library is full! Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Book ID: ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("[Error] Invalid ID. Must be an integer.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == newBook.id) {
            printf("[Error] A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    clearInputBuffer();

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    newBook.is_issued = 0; 
    library[book_count] = newBook;
    book_count++;

    printf("\n[Success] Book added successfully!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("\n[Info] No books available in the library.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n--------------------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n");
}

void searchBook() {
    if (book_count == 0) {
        printf("\n[Info] The library is currently empty.\n");
        return;
    }

    int search_id;
    printf("\nEnter Book ID to search: ");
    if (scanf("%d", &search_id) != 1) {
        printf("[Error] Invalid input type.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\nBook Found!");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("\n[Error] Book with ID %d not found.\n", search_id);
}

void issueBook() {
    int issue_id;
    printf("\nEnter Book ID to issue: ");
    if (scanf("%d", &issue_id) != 1) {
        printf("[Error] Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued == 1) {
                printf("\n[Info] Sorry, this book is already issued out.\n");
            } else {
                library[i].is_issued = 1;
                printf("\n[Success] Book '%s' has been successfully issued!\n", library[i].title);
            }
            return;
        }
    }
    printf("\n[Error] Book with ID %d does not exist.\n", issue_id);
}

void returnBook() {
    int return_id;
    printf("\nEnter Book ID to return: ");
    if (scanf("%d", &return_id) != 1) {
        printf("[Error] Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (library[i].is_issued == 0) {
                printf("\n[Info] This book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\n[Success] Book '%s' returned successfully!\n", library[i].title);
            }
            return;
        }
    }
    printf("\n[Error] Book with ID %d does not exist.\n", return_id);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}