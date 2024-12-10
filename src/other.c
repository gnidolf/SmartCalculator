#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int my_isspace(int c) { return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f' || c == '\v'); }

int isOperator(char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'; }

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 3;
    }

    if (ch == 'S' || ch == 'C' || ch == 'T' || ch == 'G' || ch == 'R' || ch == 'L') {
        return 4;
    }
    return 0;
}

int my_isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

void checkAndPushFunction(const char *infix, int *i, Stack *stack) {
    if (strncmp(infix + (*i), "sin", 3) == 0) {
        push(stack, 'S');
        *i += 2;
    } else if (strncmp(infix + (*i), "cos", 3) == 0) {
        push(stack, 'C');
        *i += 2;
    } else if (strncmp(infix + (*i), "tan", 3) == 0) {
        push(stack, 'T');
        *i += 2;
    } else if (strncmp(infix + (*i), "ctg", 3) == 0) {
        push(stack, 'G');
        *i += 2;
    } else if (strncmp(infix + (*i), "sqrt", 4) == 0) {
        push(stack, 'R');
        *i += 3;
    } else if (strncmp(infix + (*i), "ln", 2) == 0) {
        push(stack, 'L');
        *i += 1;
    }
}

int my_isalpha(int c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }