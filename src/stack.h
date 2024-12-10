#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char ch);
char pop(Stack *s);
char peek(Stack *s);

#endif