//Ques 116:Write a program to Create inventory management system. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.txt"

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct();
void viewInventory();
void updateProduct();
void deleteProduct();
void searchProduct();

int main() {
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM   \n");
        printf("==================================\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product Quantity\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Numeric characters only.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProduct(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid selection! Try again.\n");
        }
    }
    return 0;
}

void addProduct() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Product p;
    printf("\nEnter Product ID (Integer): ");
    scanf("%d", &p.id);
    getchar();

    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);

    fprintf(file, "%d,%s,%d,%.2f\n", p.id, p.name, p.quantity, p.price);
    fclose(file);

    printf("Product added successfully!\n");
}

void viewInventory() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo inventory data found. Add items first!\n");
        return;
    }

    Product p;
    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");

    while (fscanf(file, "%d,%[^,],%d,%f\n", &p.id, p.name, &p.quantity, &p.price) != EOF) {
        printf("%-10d %-25s %-10d $%-10.2f\n", p.id, p.name, p.quantity, p.price);
    }
    printf("-------------------------------------------------------------\n");
    fclose(file);
}

void updateProduct() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("Error running update operational sequence!\n");
        return;
    }

    int targetId, found = 0, newQty;
    Product p;

    printf("\nEnter Product ID to update quantity: ");
    scanf("%d", &targetId);

    while (fscanf(file, "%d,%[^,],%d,%f\n", &p.id, p.name, &p.quantity, &p.price) != EOF) {
        if (p.id == targetId) {
            found = 1;
            printf("Current Quantity for %s: %d\n", p.name, p.quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &newQty);
            p.quantity = newQty;
        }
        fprintf(tempFile, "%d,%s,%d,%.2f\n", p.id, p.name, p.quantity, p.price);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Stock quantity updated successfully.\n");
    } else {
        printf("Product with ID %d not found.\n", targetId);
    }
}

void deleteProduct() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error running delete operational sequence!\n");
        return;
    }

    int targetId, found = 0;
    Product p;

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &targetId);

    while (fscanf(file, "%d,%[^,],%d,%f\n", &p.id, p.name, &p.quantity, &p.price) != EOF) {
        if (p.id == targetId) {
            found = 1;
            continue;
        }
        fprintf(tempFile, "%d,%s,%d,%.2f\n", p.id, p.name, p.quantity, p.price);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Product deleted from system.\n");
    } else {
        printf("Product with ID %d not found.\n", targetId);
    }
}

void searchProduct() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetId, found = 0;
    Product p;

    printf("\nEnter Product ID to search: ");
    scanf("%d", &targetId);

    while (fscanf(file, "%d,%[^,],%d,%f\n", &p.id, p.name, &p.quantity, &p.price) != EOF) {
        if (p.id == targetId) {
            found = 1;
            printf("\nProduct Found:\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Quantity: %d\n", p.quantity);
            printf("Price: $%.2f\n", p.price);
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", targetId);
    }
    fclose(file);
}