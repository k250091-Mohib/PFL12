#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numEntries;
    char **feedbackArray = NULL;
    char *longestFeedback;
    int totalChars = 0;
    int maxLength = 0;
    int longestIndex = 0;
    int capacity = 2;
    int count = 0;
    char buffer[1000];
    char choice;

    printf("STUDENT FEEDBACK ANALYSIS SYSTEM\n");
    feedbackArray = (char**)malloc(capacity * sizeof(char*));
    if (feedbackArray == NULL) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    do {
        if (count >= capacity) {
            capacity *= 2;
            feedbackArray = (char**)realloc(feedbackArray, capacity * sizeof(char*));
            if (feedbackArray == NULL) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
            printf("Array resized to capacity: %d\n", capacity);
        }
        printf("\nEnter feedback entry %d: ", count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        feedbackArray[count] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (feedbackArray[count] == NULL) {
            printf("Memory allocation failed for feedback %d!\n", count + 1);
            return 1;
        }
        strcpy(feedbackArray[count], buffer);
        int currentLength = strlen(feedbackArray[count]);
        totalChars += currentLength;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestIndex = count;
        }

        count++;
        printf("Add another feedback entry? (y/n): ");
        fgets(buffer, sizeof(buffer), stdin);
        choice = buffer[0];

    } while (choice == 'y' || choice == 'Y');
    printf("\nALL FEEDBACK ENTRIES\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d: %s\n", i + 1, feedbackArray[i]);
        printf("Length: %d characters\n", strlen(feedbackArray[i]));
    }

    printf("\n=== ANALYSIS RESULTS ===\n");
    printf("Total number of feedback entries: %d\n", count);
    printf("Total number of characters: %d\n", totalChars);
    if (count > 0) {
        printf("Average characters per entry: %.2f\n", (float)totalChars / count);
        printf("Longest feedback (Entry %d): %s\n", longestIndex + 1, feedbackArray[longestIndex]);
        printf("Length of longest feedback: %d characters\n", maxLength);
        
        printf("\nFinding longest entry using pointer traversal:\n");
        maxLength = 0;
        longestIndex = 0;
        char **ptr = feedbackArray;
        
        for (int i = 0; i < count; i++) {
            int length = strlen(*ptr);
            if (length > maxLength) {
                maxLength = length;
                longestIndex = i;
            }
            ptr++;
        }
        printf("Longest entry confirmed: Entry %d (%d characters)\n", longestIndex + 1, maxLength);
    }

    printf("\nFreeing memory...\n");
    for (int i = 0; i < count; i++) {
        free(feedbackArray[i]);
        printf("Freed memory for entry %d\n", i + 1);
    }
    free(feedbackArray);
    printf("All memory freed successfully.\n");
    return 0;
}