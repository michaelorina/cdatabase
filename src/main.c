#include <stdio.h>
#include <string.h>
#include "../include/db.h"

int main() {
    load_from_file();

    char key[50];
    char value[100];
    int choice;

    while (1) {
        printf("\n1. Set Key-Value\n2. Get Value\n3. Delete Key\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;

                printf("Enter value: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0;

                set(key, value);
                printf("Stored: %s = %s\n", key, value);
                break;

            case 2:
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;

                char *result = get(key);
                if (result)
                    printf("Value: %s\n", result);
                else
                    printf("Key not found.\n");
                break;

            case 3:
                printf("Enter key to delete: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;

                delete_entry(key);
                printf("Deleted key: %s\n", key);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}