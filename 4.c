#include <stdio.h>
#include <stdlib.h>
int main() {
    int numCategories;
    int *ratings;
    int choice, categoryToUpdate, newRating;
    int totalRatings, highestRating, highestIndex;
    float averageRating;
    printf("Enter the number of movie categories: ");
    scanf("%d", &numCategories);
    if (numCategories <= 0) {
        printf("Number of categories must be positive.\n");
        return 1;
    }
    ratings = (int*)malloc(numCategories * sizeof(int));
    if (ratings == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("\nEnter rating counts for each category:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: ", i + 1);
        scanf("%d", &ratings[i]);   
        if (ratings[i] < 0) {
            printf("Rating count cannot be negative. Setting to 0.\n");
            ratings[i] = 0;
        }
    }
    
    choice = 0;
    while (choice != 2) {
        totalRatings = 0;
        highestRating = ratings[0];
        highestIndex = 0;
        
        for (int i = 0; i < numCategories; i++) {
            totalRatings += ratings[i];
            if (ratings[i] > highestRating) {
                highestRating = ratings[i];
                highestIndex = i;
            }
        }
        averageRating = (float)totalRatings / numCategories;
        
        printf("\nMOVIE CATEGORY RATING ANALYSIS\n");
        printf("Total ratings across all categories: %d\n", totalRatings);
        printf("Average ratings per category: %.2f\n", averageRating);
        printf("Category with highest rating count: Category %d (%d ratings)\n", highestIndex + 1, highestRating);
        printf("\nCurrent rating counts:\n");
        for (int i = 0; i < numCategories; i++) {
            printf("Category %d: %d ratings\n", i + 1, ratings[i]);
        }
        
        printf("\nOptions:\n");
        printf("1. Update rating count of a category\n");
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
                printf("Enter new rating count for category %d: ", categoryToUpdate);
                scanf("%d", &newRating);
                if (newRating < 0) {
                    printf("Rating count cannot be negative. Setting to 0.\n");
                    newRating = 0;
                }
                ratings[categoryToUpdate - 1] = newRating;
                printf("Rating updated successfully!\n");
                break;
            case 2:printf("Exiting program...\n");break;
            default:printf("Invalid choice! Please try again.\n");
        }
    }
    free(ratings);
    printf("Memory freed successfully. Program ended.\n");
    return 0;
}