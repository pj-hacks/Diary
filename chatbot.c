#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QA 1000
#define MAX_LEN 256

char questions[MAX_QA][MAX_LEN];
char answers[MAX_QA][MAX_LEN];
int qa_count = 0;

char pending_question[MAX_LEN] = ""; // For learning mode

// Trim newline from fgets
void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

// Convert string to lowercase
void to_lowercase(char *str) {
    for (; *str; ++str) {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
    }
}

// Load training data from file
void load_training_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    char line[MAX_LEN * 2];
    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        char *sep = strchr(line, ':');
        if (sep) {
            *sep = '\0';
            strncpy(questions[qa_count], line, MAX_LEN);
            strncpy(answers[qa_count], sep + 1, MAX_LEN);
            ++qa_count;
        }
    }

    fclose(fp);
}

// Save new pair to training.txt
void save_to_file(const char *question, const char *answer) {
    FILE *fp = fopen("training.txt", "a");
    if (fp) {
        fprintf(fp, "%s:%s\n", question, answer);
        fclose(fp);
    }
}

// Search known questions
char *get_answer(const char *input) {
    for (int i = 0; i < qa_count; ++i) {
        if (strcasecmp(input, questions[i]) == 0)
            return answers[i];
    }
    return NULL;
}

int main() {
    char input[MAX_LEN];

    load_training_data("training.txt");

    printf("Chatbot Ready. Type 'exit' to quit.\n");

    while (1) {
        printf("You: ");
        if (!fgets(input, MAX_LEN, stdin)) break;
        trim_newline(input);

        if (strcasecmp(input, "exit") == 0)
            break;

        // If waiting for user to teach
        if (strlen(pending_question) > 0) {
            strncpy(answers[qa_count], input, MAX_LEN);
            strncpy(questions[qa_count], pending_question, MAX_LEN);
            ++qa_count;

            save_to_file(pending_question, input);

            printf("AI: Thank you, I've learned it.\n");
            pending_question[0] = '\0'; // Clear pending
            continue;
        }

        char *response = get_answer(input);
        if (response) {
            printf("AI: %s\n", response);
        } else {
            printf("AI: I don't know the answer. Please teach me.\n");
            strncpy(pending_question, input, MAX_LEN);
        }
    }

    return 0;
}
