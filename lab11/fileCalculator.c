#include "fileCalculator.h"

int setPriority(char operation) {
    int priority = 0;
    switch (operation) {
    case '*': case '/': priority = 2; break;
    case '+': case '-': priority = 1; break;
    }
    return priority;
}

double doOperation(double firstDigit, double secondDigit, char operation) {
    double result = 0;
    switch(operation) {
        case '+': result = firstDigit + secondDigit; break;
        case '-': result = firstDigit - secondDigit; break;
        case '*': result = firstDigit * secondDigit; break;
        case '/': result = firstDigit / secondDigit; break;
    }
    return result;
}

void calculate(Stack **numbers, Stack **operations) {
    double secondDigit = *(double*)pop(numbers), firstDigit = *(double*)pop(numbers);
    double *result = (double*)malloc(sizeof(double));
    *result = doOperation(firstDigit, secondDigit, *(char*)pop(operations));
    *numbers = push(*numbers, result);
}

bool errorsCatch(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char inputChar, previosChar;
        char approvedChars[] = {'+', '-', '*', '/', '(', ')', '.', '\n', '\0'};
        int bracketsBalance = 0;

        fscanf(file, "%c", &previosChar);
        if (previosChar == '(')
            bracketsBalance++;
        else if (previosChar == ')') {
            printf("The opening bracket is missed on %ld position.\n", ftell(file) - 1);
            return false;
        }
        while (fscanf(file, "%c", &inputChar) != EOF) {
            if (!contains(approvedChars, inputChar) && !(inputChar >= '0' && inputChar <= '9')) {
                printf("Wrong char in %ld position.\n", ftell(file) - 1);
                return false;
            } else if (contains(approvedChars, inputChar) && contains(approvedChars, previosChar) && previosChar != ')' && inputChar != '(' && !(previosChar == '(' && inputChar == '-')) {
                printf("Digit was missed on %ld position.\n", ftell(file) - 1);
                printf("%c %c", previosChar, inputChar);
                return false;
            } else if (previosChar == ')' && inputChar == '(') {
                printf("There must be an operation sign between the brackets on %ld position.\n", ftell(file) - 1);
                return false;
            } else if (inputChar == '(') {
                bracketsBalance++;
            } else if (inputChar == ')')
                bracketsBalance--;
            if (bracketsBalance < 0) {
                printf("The opening bracket is missed on %ld position.\n", ftell(file) - 1);
                return false;
            }
            previosChar = inputChar;
        }

        if (bracketsBalance != 0) {
            printf("The closing bracket was missed on %ld position.\n", ftell(file) - 1);
            return false;
        }
        return true;
    } else {
        perror("Opening error"), getch();
        return false;
    }
}

void calculateFile(char *filename) {
    if (errorsCatch(filename)) {
        FILE *file = fopen(filename, "r+"), *output = fopen("output.txt", "w");
        Stack *numbers, *operations;
        char operators[] = {'*', '/', '-', '+'}, inputChar, prevChar = '\0';
        int status = 0;
        bool isNegative = false;

        while (status != EOF) {
            numbers = NULL, operations = NULL;
            status = fscanf(file, "%c", &inputChar);

            while (status != -1 && inputChar != '\n') {
                char *inputChar_p = (char *)safeMalloc(sizeof(char));
                *inputChar_p = inputChar;

                if (inputChar >= '0' && inputChar <= '9') {
                    double *number = (double *)safeMalloc(sizeof(double));
                    int pos = ftell(file) - 1;
                    fclose(file);
                    pos = getDigit(number, filename, pos);
                    if (isNegative) {
                        *number = *number * -1;
                        isNegative = false;
                    }
                    numbers = push(numbers, number);
                    file = fopen(filename, "r+");
                    fseek(file, pos, SEEK_SET);
                }else if (inputChar == '-' && prevChar == '(') isNegative = true;
                else if (contains(operators, inputChar)) {
                    int priority = setPriority(inputChar), operationsPriority = operations == NULL ? -1 : setPriority(*(char *)operations->data);
                    if (priority > operationsPriority)
                        operations = push(operations, inputChar_p);
                    else {
                        while (priority <= operationsPriority) {
                            calculate(&numbers, &operations);
                            operationsPriority = operations == NULL ? -1 : setPriority(*(char *)operations->data);
                        }
                        operations = push(operations, inputChar_p);
                    }
                } else if (inputChar == '(')
                    operations = push(operations, inputChar_p);
                else if(prevChar != '-') {
                    while (*(char *)operations->data != '(')
                        calculate(&numbers, &operations);
                    pop(&operations);
                }
                prevChar = inputChar;
                status = fscanf(file, "%c", &inputChar);
            }

            while (operations != NULL)
                calculate(&numbers, &operations);
            fprintf(output, "%lf\n", *(double *)pop(&numbers));
        }
        fclose(file);
        fclose(output);
        free(numbers);
        free(operations);
        puts("Results were written in output.txt file."); getch();
    }
    
}