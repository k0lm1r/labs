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

void calculate(stackDouble **numbers, stackChar **operations) {
    double secondDigit = popDouble(numbers), firstDigit = popDouble(numbers);
    double result = doOperation(firstDigit, secondDigit, popChar(operations));
    pushDouble(numbers, result);
}

bool errorsCatch(char *filename) {
    FILE *file = fopen(filename, "r");
    char inputChar, previosChar;
    char approvedChars[] = {'+', '-', '*', '/', '(', ')', '.', '\n', '\0'};
    int bracketsBalance = 0, firstBracketPos = 0;

    fscanf(file, "%c", &previosChar);
    while (fscanf(file, "%c", &inputChar) != EOF) {
        if (!contains(approvedChars, inputChar) && !(inputChar >= '0' && inputChar <= '9')) {
            printf("Wrong char in %d position.\n", ftell(file) - 1);
            return false;
        } else if (contains(approvedChars, inputChar) && contains(approvedChars, previosChar) && previosChar != ')' && inputChar != '(' && !(previosChar == '(' && inputChar == '-')) {
            printf("Digit was missed on %d position.\n", ftell(file) - 1);
            printf("%c %c", previosChar, inputChar);
            return false;
        } else if (previosChar == ')' && inputChar == '(') {
            printf("There must be an operation sign between the brackets on %d position.\n", ftell(file) - 1);
            return false;
        } else if (inputChar == '(') {
            bracketsBalance++;
            firstBracketPos = ftell(file) - 1;
        } else if (inputChar == ')') bracketsBalance--;
        if (bracketsBalance < 0) {
            printf("The opening bracket is missed on %d position.\n", ftell(file) - 1);
            return false;
        }
        previosChar = inputChar;
    }

    if (bracketsBalance != 0) {
        printf("The closing bracket was missed on %d position.\n", ftell(file) - 1);
        return false;
    }
    return true;
}

void calculateFile(char *filename) {
    if (errorsCatch(filename)) {
        FILE *file = fopen(filename, "r+"), *output = fopen("output.txt", "w");
        stackDouble *numbers;
        stackChar *operations;
        char operators[] = {'*', '/', '-', '+'}, inputChar;
        int status = 0;

        while (status != EOF) {
            numbers = NULL, operations = NULL;
            status = fscanf(file, "%c", &inputChar);
            while (status != -1 && inputChar != '\n') {
                if (inputChar >= '0' && inputChar <= '9') {
                    double number = 0;
                    int pos = ftell(file) - 1;
                    fclose(file);
                    pos = getDigit(&number, filename, pos);
                    pushDouble(&numbers, number);
                    file = fopen(filename, "r+");
                    fseek(file, pos, SEEK_SET);
                } else if (contains(operators, inputChar)) {
                    int priority = setPriority(inputChar), operationsPriority = operations == NULL ? -1 : setPriority(operations->data);
                    if (priority > operationsPriority)
                        pushChar(&operations, inputChar);
                    else {
                        while (priority <= operationsPriority) {
                            calculate(&numbers, &operations);
                            operationsPriority = operations == NULL ? -1 : setPriority(operations->data);
                        }
                        pushChar(&operations, inputChar);
                    }
                } else if (inputChar == '(')
                    pushChar(&operations, inputChar);
                else {
                    while (operations->data != '(')
                        calculate(&numbers, &operations);
                    popChar(&operations);
                }
                status = fscanf(file, "%c", &inputChar);
            }
            while (operations != NULL)
                calculate(&numbers, &operations);
            fprintf(output, "%lf\n", popDouble(&numbers));
        }
        fclose(file);
        free(numbers);
        free(operations);
    }
}