#include "stack.h"

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, char ch) {
    if (s->top < MAX_SIZE - 1) {
        s->stack[++(s->top)] = ch;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top];
    }
    return '\0';
}