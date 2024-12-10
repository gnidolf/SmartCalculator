#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "other.h"
#include "stack.h"

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initStack(&stack);

    int i = 0;
    int pi = 0;

    while (infix[i] != '\0') {
        if (my_isdigit(infix[i]) || infix[i] == '.') {
            while (my_isdigit(infix[i]) || infix[i] == '.') {
                postfix[pi++] = infix[i++];
            }
            postfix[pi++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[pi++] = pop(&stack);
                postfix[pi++] = ' ';
            }
            pop(&stack);
            if (!isEmpty(&stack) && strchr("SCTGRL", peek(&stack))) {
                postfix[pi++] = pop(&stack);
                postfix[pi++] = ' ';
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[pi++] = pop(&stack);
                postfix[pi++] = ' ';
            }
            push(&stack, infix[i]);
        } else if (my_isalpha(infix[i])) {
            checkAndPushFunction(infix, &i, &stack);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[pi++] = pop(&stack);
        postfix[pi++] = ' ';
    }
    postfix[pi] = '\0';
}

double evaluate_polish_notation(char *expression) {
    double stack[MAX_SIZE] = {0};
    int top = -1;
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (my_isdigit(token[0]) || (token[0] == '-' && my_isdigit(token[1])) ||
            (token[0] == '-' && token[1] == '\0' && (top == -1 || !my_isdigit(stack[top])))) {
            if (token[0] == '-' && token[1] == '\0') {
                stack[top] = -stack[top];
            } else
                stack[++top] = atof(token);
        } else if (strcmp(token, "S") == 0 || strcmp(token, "C") == 0 || strcmp(token, "T") == 0 ||
                   strcmp(token, "G") == 0 || strcmp(token, "L") == 0 || strcmp(token, "R") == 0) {
            double operand = stack[top--];
            if (strcmp(token, "S") == 0) {
                stack[++top] = sin(operand);
            } else if (strcmp(token, "C") == 0) {
                stack[++top] = cos(operand);
            } else if (strcmp(token, "T") == 0) {
                stack[++top] = tan(operand);
            } else if (strcmp(token, "G") == 0) {
                stack[++top] = 1 / tan(operand);
            } else if (strcmp(token, "L") == 0) {
                stack[++top] = log(operand);
            } else if (strcmp(token, "R") == 0)
                stack[++top] = sqrt(operand);
        } else {
            double operand2 = stack[top--];
            double operand1 = stack[top--];
            switch (token[0]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                default:
                    return -1;
            }
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}