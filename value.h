#include <math.h>
#include <string.h>

#include "stack.h"
void oper_binar(struct expres **head, char *tok, int *er);
void oper_ynar(struct expres **head, char *tok, int *er);
double value(char *exit, double x, int *error);