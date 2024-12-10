#include "graph_lib.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "other.h"
#include "polish_not.h"
#include "stack.h"

void draw_field(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

void draw_graph() {
    char field[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            field[i][j] = '.';
        }
    }

    double step = (4 * M_PI) / (WIDTH - 1);
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);

    for (int j = 0; j < WIDTH; ++j) {
        double x = j * step;
        char infix[MAX_SIZE], postfix[MAX_SIZE];
        char input_copy[MAX_SIZE];
        strcpy(input_copy, input);

        int input_idx = 0;
        for (size_t i = 0; i < strlen(input_copy); i++) {
            if (input_copy[i] == 'x') {
                input_idx += snprintf(&infix[input_idx], MAX_SIZE - input_idx, "%.10lf", x);
            } else if (!my_isspace(input_copy[i])) {
                infix[input_idx++] = input_copy[i];
            }
        }
        infix[input_idx] = '\0';

        infixToPostfix(infix, postfix);

        double result = evaluate_polish_notation(postfix);
        int result_new = round((result + 1) * (HEIGHT - 1) / 2);

        if (result_new >= 0 && result_new < HEIGHT) {
            field[result_new][j] = '*';
        }
    }

    draw_field(field);
}