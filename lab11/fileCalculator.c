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

void calculateFile(char *filename) {
    FILE *file = fopen(filename, "r+");
    stackDouble *numbers = NULL;
    stackChar *operations = NULL;
    char operators[] = {'*', '/', '-', '+'}, inputChar;

    while (fscanf(file, "%c", &inputChar) != EOF) {
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
                    operationsPriority = setPriority(operations->data);
                }
                pushChar(&operations, inputChar);
            }
        }else if (inputChar == '(') pushChar(&operations, inputChar);
        else {
            while (operations->data != '(')
                calculate(&numbers, &operations);
            popChar(&operations);
        }
    }
    while (operations != NULL) calculate(&numbers, &operations);

    printf("%lf", popDouble(&numbers));
    fclose(file);
    free(numbers);
    free(operations);
}