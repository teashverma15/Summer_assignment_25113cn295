//Ques 118:Write a program to Create mini library system.
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[100];
    int count = 0, choice;

    do {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add Book\n2. Display All Books\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Book ID: ");
            scanf("%d", &library[count].id);
            getchar(); 
            printf("Enter Title: ");
            fgets(library[count].title, 50, stdin);
            library[count].title[strcspn(library[count].title, "\n")] = 0;
            printf("Enter Author: ");
            fgets(library[count].author, 50, stdin);
            library[count].author[strcspn(library[count].author, "\n")] = 0;
            count++;
        } 
        else if (choice == 2) {
            printf("\nID\tTitle\t\tAuthor\n");
            for (int i = 0; i < count; i++) {
                printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
            }
        }
    } while (choice != 3);

    return 0;
}