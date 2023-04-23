#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
void oper_binar(struct expres **head, char *tok, int *er);
void oper_ynar(struct expres **head, char *tok, int *er);
double value(char *exit_, double x, int *error) {
    double res = 0;
    struct expres *head = NULL;
    head = malloc(sizeof(struct expres));
    char *exit = malloc(strlen(exit_) * sizeof(char));
    strcpy(exit, exit_);
    char *tok = strtok(exit, " ");
    while (tok != 0 && *error != 0) {
        if (tok[0] == '-' || tok[0] == '+' || tok[0] == '/' || tok[0] == '*') {
            oper_binar(&head, &tok[0], error);
        } else if (tok[0] == 's' || tok[0] == 'c' || tok[0] == 't' || tok[0] == 'l' || tok[0] == '~' ||
                   tok[0] == 'k' || tok[0] == '$') {
            oper_ynar(&head, &tok[0], error);
        } else if (tok[0] == 'x')
            push_expres(&head, x);
        else {
            char *s;
            double a = strtod(tok, &s);
            push_expres(&head, a);
        }
        tok = strtok(0, " ");
    }
    if (*error == 1) {
        res = (double)(head->value);
    }
    // free(head->next);
    free(exit);
    destroy(head);
    // free(head);
    return res;
}
void oper_binar(struct expres **head, char *tok, int *er) {
    double num_1 = pop_expres(head);
    double num_2 = pop_expres(head);
    *er = 1;
    switch (*tok) {
        case '-':
            push_expres(head, num_2 - num_1);
            break;
        case '+':
            push_expres(head, num_2 + num_1);
            break;
        case '*':
            push_expres(head, num_2 * num_1);
            break;
        case '/':
            if (num_1 != 0)
                push_expres(head, num_2 / num_1);
            else
                *er = 0;
            break;
    }
}
void oper_ynar(struct expres **head, char *tok, int *er) {
    double num_1 = pop_expres(head);
    switch (*tok) {
        case '~':
            push_expres(head, 0 - num_1);
            break;
        case 's':
            push_expres(head, sin(num_1));
            break;
        case 'c':
            push_expres(head, cos(num_1));
            break;
        case 't':
            if (cos(num_1) != 0)
                push_expres(head, tan(num_1));
            else
                *er = 0;
            break;
        case '$':
            if (num_1 >= 0)
                push_expres(head, sqrt(num_1));
            else
                *er = 0;
            break;
        case 'k':
            push_expres(head, 1 / tan(num_1));
            break;
        case 'l':
            if (num_1 < 0)
                *er = 0;
            else {
                num_1 += 0.00000000000001;
                push_expres(head, log(num_1));
            }
            break;
    }
}
