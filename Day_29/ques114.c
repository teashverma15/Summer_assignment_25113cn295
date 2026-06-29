//Ques 114:Write a program to Create menu-driven array operations system. 
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, choice, pos, element, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (1) {
        printf("\n--- MENU ---\n1. Traverse\n2. Insert\n3. Delete\n4. Search\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                display(arr, n);
                break;

            case 2: 
                printf("Enter position (0 to %d) and element: ", n);
                scanf("%d %d", &pos, &element);
                for (int i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
                arr[pos] = element;
                n++;
                display(arr, n);
                break;

            case 3: 
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
                display(arr, n);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == element) {
                        printf("Element found at index %d\n", i);
                        found = 1; break;
                    }
                }
                if (!found) printf("Element not found.\n");
                break;

            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}