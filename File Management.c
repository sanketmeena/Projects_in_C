#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char fileName[50];
    FILE *file;

    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(file);
}

void deleteFile() {
    char fileName[50];

    printf("Enter the name of the file to delete: ");
    scanf("%s", fileName);

    if (remove(fileName) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting file.\n");
    }
}

void displayFile() {
    char fileName[50];
    FILE *file;
    char ch;

    printf("Enter the name of the file to display: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Contents of the file:\n");

    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("File Management System\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Display file contents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                displayFile();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    } while (1);

    return 0;
}
