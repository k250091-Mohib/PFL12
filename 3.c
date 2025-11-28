#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int containsDigit(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    char **usernames;
    char temp[100];
    printf("Enter number of usernames: ");
    scanf("%d", &n);
    getchar();
    usernames = (char**)malloc(n * sizeof(char*));
    printf("Enter %d usernames:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Username %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';
        usernames[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(usernames[i], temp);
    }

    printf("\nUsernames without digits:\n");
    for (int i = 0; i < n; i++) {
        if (!containsDigit(usernames[i])) {
            printf("%s\n", usernames[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        free(usernames[i]);
    }
    free(usernames);
    return 0;
}