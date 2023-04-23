#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(stack **root, char data) {
    stack *temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL) {
        puts("No memory");
        exit(-1);
    }
    temp->c = data;
    temp->next = *root;
    *root = temp;
}
char pop(stack **HEAD) {
    stack *temp;
    char a;
    if (*HEAD == NULL) return '\0';
    temp = *HEAD;
    a = temp->c;
    *HEAD = temp->next;
    free(temp);
    return a;
}
void push_expres(struct expres **head, double val) {
    struct expres *temp = (struct expres *)malloc(sizeof(struct expres));
    if (temp == NULL) {
        puts("No memory");
        exit(-1);
    }
    temp->value = val;
    temp->next = *head;
    *head = temp;
}
void destroy(struct expres *root) {
    while (root) {
        struct expres *temp = root;
        root = root->next;
        free(temp);
    }
    free(root);
}

double pop_expres(struct expres **head) {
    struct expres *temp;
    double a;
    if (*head == NULL) return '\0';
    temp = *head;
    a = temp->value;
    *head = temp->next;
    free(temp);
    return a;
}
