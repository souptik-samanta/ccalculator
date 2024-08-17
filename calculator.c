#include <stdio.h>

int calc(int n1, int n2, char op);

int firstNumber, secondNumber;
char oper;
char input[100];
char userDecision;
char exitCmd[30];

int main () {

    printf("Type `exit` to exit. \n");
    if (exitCmd != "exit") {
        printf("Enter first number: ");
        fgets(input, sizeof(input), stdin);
        firstNumber = atoi(input);
        printf("Enter second number: ");
        fgets(input, sizeof(input), stdin);
        secondNumber = atoi(input);
        printf("Enter operator: ");
        fgets(input, sizeof(input), stdin);
        oper = input[0];

        printf("The first number is %d, the second number is %d, the operator is %c . Enter (Y/N) to confirm ", firstNumber, secondNumber, oper);
        fgets(input, sizeof(input), stdin);
        userDecision = input[0];

        if (userDecision=='Y' || userDecision=='y') {
            printf("%d \n", calc(firstNumber, secondNumber, oper));
        } else {
            main();
        }

        fgets(exitCmd, sizeof(exitCmd), stdin);
    }
    return 0;
}

int calc(int n1, int n2, char op) {
    int result;

    switch (op) {
        case '+': {
            result = n1 + n2;
            break;
        }
        case '-': {
            result = n1 - n2;
            break;
        }
        case '*': {
            result = n1 * n2;
            break;
        }
        case '/': {
            if (n2 != 0){
                 result = n1 / n2;
            }
            else {
                printf("Division by zero not possible.");
                return 1;
            }
            break;
        }
        default: {
            printf("Operator not recognized.");
            return 1;
        }
    }

    return result;
}
