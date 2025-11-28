#include <stdio.h>
#include <stdlib.h>
int main() {
    int numCategories;
    int *stockLevels;
    int choice, categoryToUpdate, newStock;
    printf("Enter the number of book categories: ");
    scanf("%d", &numCategories);
    
    if (numCategories <= 0) {
        printf("Number of categories must be positive.\n");
        return 1;
    }
    
    stockLevels = (int*)malloc(numCategories * sizeof(int));
    if (stockLevels == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("\nEnter stock quantities for each category:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: ", i + 1);
        scanf("%d", &stockLevels[i]);
        
        if (stockLevels[i] < 0) {
            printf("Stock cannot be negative. Setting to 0.\n");
            stockLevels[i] = 0;
        }
    }
    
    do {
        int totalStock = 0;
        int minStock = stockLevels[0];
        int minIndex = 0;
        
        for (int i = 0; i < numCategories; i++) {
            totalStock += stockLevels[i];
            if (stockLevels[i] < minStock) {
                minStock = stockLevels[i];
                minIndex = i;
            }
        }
        
        float averageStock = (float)totalStock / numCategories;
        
        printf("\nBOOK STOCK MANAGEMENT SYSTEM\n");
        printf("Total stock: %d\n", totalStock);
        printf("Average stock per category: %.2f\n", averageStock);
        printf("Category with lowest stock: Category %d (%d items)\n", minIndex + 1, minStock);
        printf("\nCurrent stock levels:\n");
        for (int i = 0; i < numCategories; i++) {
            printf("Category %d: %d items\n", i + 1, stockLevels[i]);
        }
        
        printf("\nOptions:\n");
        printf("1. Update stock of a category\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter category number to update (1-%d): ", numCategories);
                scanf("%d", &categoryToUpdate);
                if (categoryToUpdate < 1 || categoryToUpdate > numCategories) {
                    printf("Invalid category number!\n");
                    break;
                }
                printf("Enter new stock quantity for category %d: ", categoryToUpdate);
                scanf("%d", &newStock);
                if (newStock < 0) {
                    printf("Stock cannot be negative. Setting to 0.\n");
                    newStock = 0;
                }
                stockLevels[categoryToUpdate - 1] = newStock;
                printf("Stock updated successfully!\n");
                break;
            case 2:printf("Exiting program...\n");break;
            default:printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 2);
    free(stockLevels);
    printf("Memory freed successfully. Program ended.\n");   
    return 0;
}