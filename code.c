#include <stdio.h>
#include <stdlib.h>

// Function to log each calculation into a history file
void log_history(float num1, char op, float num2, float result) {
    FILE *file = fopen("calc_history.txt", "a");
    if (file == NULL) {
        printf("Unable to open history file.\n");
        return;
    }
    fprintf(file, "%.2f %c %.2f = %.2f\n", num1, op, num2, result);
    fclose(file);
}

// Function to display calculation history
void show_history() {
    FILE *file = fopen("calc_history.txt", "r");
    if (file == NULL) {
        printf("No history available.\n");
        return;
    }
    char ch;
    printf("\n----- Calculation History -----\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("-------------------------------\n");
}

int main() {
    float num1, num2, result;
    char op;
    char choice;

    do {
        printf("\nEnter first number: ");
        scanf("%f", &num1);
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op);
        printf("Enter second number: ");
        scanf("%f", &num2);

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator!\n");
                continue;
        }

        printf("Result: %.2f\n", result);
        log_history(num1, op, num2, result);

        printf("Do you want to view history? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            show_history();
        }

        printf("Do another calculation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}
