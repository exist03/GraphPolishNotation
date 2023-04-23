#include <stdio.h>

#include "stack.h"
int check_operations(int k, const char* a);
int priora(char a);
void convert(char* a, char* exit, stack* oper) {
    int k = 0, point = 0;
    exit[point++] = ' ';
    while (a[k] != '\0') {
        if (a[k] == ')') {
            while ((oper->c) != '(') {
                exit[point++] = ' ';
                exit[point++] = pop(&oper);
                exit[point++] = ' ';
            }
            pop(&oper);
        } else if (a[k] == '(') {
            push(&oper, a[k]);
        } else if (check_operations(k, a)) {
            if (a[k] == '-' && (k == 0 || a[k - 1] == '(')) {
                push(&oper, '~');
            } else if (oper == NULL) {
                push(&oper, a[k]);
            } else if (priora(a[k]) > priora(oper->c)) {
                push(&oper, a[k]);
            } else {
                while (oper != NULL && priora(oper->c) >= priora(a[k])) {
                    exit[point++] = pop(&oper);
                    exit[point++] = ' ';
                }
                push(&oper, a[k]);
            }
        } else if (check_operations(k + 1, a)) {
            exit[point++] = a[k];
            exit[point++] = ' ';
        } else {
            exit[point++] = a[k];
        }
        k++;
    }
    while (oper != NULL) {
        exit[point++] = ' ';
        exit[point++] = pop(&oper);
        exit[point++] = ' ';
    }
    exit[point] = '\0';
}

int check_operations(int k, const char* a) {
    return a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*' || a[k] == 's' || a[k] == 'c' ||
           a[k] == 't' || a[k] == 'k' || a[k] == '$' || a[k] == 'l';
}

int priora(char a) {
    int result = -1;
    if (a == '~') {
        result = 4;
    } else if (a == 'l' || a == '$' || a == 'k' || a == 't' || a == 'c' || a == 's') {
        result = 5;
    } else if (a == '*' || a == '/') {
        result = 3;
    } else if (a == '+' || a == '-') {
        result = 2;
    } else if (a == '(') {
        result = 1;
    }
    return result;
}
