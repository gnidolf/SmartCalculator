#ifndef OTHER_H
#define OTHER_H
#include "stack.h"
int isOperator(char c);
int precedence(char op);
int my_isdigit(char c);
void infixToPostfix(char infix[], char postfix[]);
void checkAndPushFunction(const char *infix, int *i, Stack *stack);
int my_isalpha(int c);
int my_isspace(int c);
#endif