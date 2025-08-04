#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 10000

int main() {
    char paragraph[MAX_LEN];
    char words[MAX_WORDS][50];
    int freq[MAX_WORDS] = {0};
    int word_count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_LEN, stdin);

    // Convert paragraph to lowercase and replace punctuation with spaces
    for (int i = 0; paragraph[i]; i++) {
        if (ispunct(paragraph[i])) {
            paragraph[i] = ' ';
        } else {
            paragraph[i] = tolower(paragraph[i]);
        }
    }

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[word_count], token);
            freq[word_count] = 1;
            word_count++;
        }
        token = strtok(NULL, " \n\t");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
