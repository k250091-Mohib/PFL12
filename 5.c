#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char getCategory(char ch) {
    if (isupper(ch)) return 'U';
    if (islower(ch)) return 'L';
    if (isdigit(ch)) return 'D';
    return 'S';
}

int main() {
    int n;
    printf("Enter number of participants: ");
    scanf("%d", &n);
    getchar();
    char *pattern = (char *)malloc(100 * sizeof(char));
    if (!pattern) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter password pattern: ");
    fgets(pattern, 100, stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    int patternLen = strlen(pattern);
    char **passwords = (char **)malloc(n * sizeof(char *));
    float *scores = (float *)malloc(n * sizeof(float));

    if (!passwords || !scores) {
        printf("Memory allocation failed.\n");
        free(pattern);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        passwords[i] = (char *)malloc(100 * sizeof(char));
        if (!passwords[i]) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter password for participant %d: ", i + 1);
        fgets(passwords[i], 100, stdin);
        passwords[i][strcspn(passwords[i], "\n")] = '\0';
        int attemptLen = strlen(passwords[i]);
        int minLen = (attemptLen < patternLen) ? attemptLen : patternLen;
        int matchCount = 0;
        for (int j = 0; j < minLen; j++) {
            if (getCategory(passwords[i][j]) == getCategory(pattern[j])) {
                matchCount++;
            }
        }
        scores[i] = ((float)matchCount / patternLen) * 100.0;
    }

    printf("\n--- Similarity Scores ---\n");
    for (int i = 0; i < n; i++) {
        printf("Password: %-15s  Similarity: %.2f%%\n",passwords[i], scores[i]);
    }

    float maxScore = scores[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxIndex = i;
        }
    }

    printf("\nMost similar password: %s\n", passwords[maxIndex]);
    printf("Highest similarity: %.2f%%\n", maxScore);

    free(pattern);
    for (int i = 0; i < n; i++) {
        free(passwords[i]);
    }
    free(passwords);
    free(scores);

    return 0;
}
