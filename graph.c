#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "stack.h"
#include "to_polish.h"

int check_operats(int k, const char *a);
void change_names(char *str, char *substr, char *res, int nums);
char *input(int *i);
int valid_input(char *str);
void input_transformation(char *str);

int main() {
    stack *oper = NULL;
    int count = 0;
    char *a = input(&count);  //чтение строки
    input_transformation(a);
    if (!valid_input(a)) {
        puts("n/a\n");
    } else {
        char *exit = (char *)malloc(2 * count * sizeof(char));
        convert(a, exit, oper);  //преобразует выражение в польскую нотацию
        display(exit);
        free(exit);
    }
    free(a);
    return 0;
}

char *input(int *i) {
    char *string = (char *)malloc(2 * sizeof(char));
    char c = getchar();
    while (c != '\n') {
        char *new = (char *)realloc(string, sizeof(char) * (*i + 1));
        if (new == NULL)
            free(string);
        else {
            string[*i] = c;
            c = getchar();
            *i += 1;
        }
    }
    string[*i] = '\0';
    return string;
}
void change_names(char *str, char *substr, char *res, int nums) {
    char *found = strstr(str, substr);
    while (found != NULL) {
        memcpy(found, res, nums);
        found = strstr(str, substr);
        continue;
    }
}
void input_transformation(char *str) {
    change_names(str, "sin", "s  ", 3);
    change_names(str, "cos", "c  ", 3);
    change_names(str, "tan", "t  ", 3);
    change_names(str, "ctg", "k  ", 3);
    change_names(str, "sqrt", "$   ", 4);
    change_names(str, "ln", "l ", 2);
}
int check_operats(int k, const char *a) { return a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*'; }
int valid_input(char *str) {
    int count_open = 0;
    int count_close = 0;
    int flag = 1;
    int lenght = strlen(str);
    for (int i = 0; i < lenght; i++) {
        if (str[i] == '(') {
            count_open++;
        } else if (str[i] == ')') {
            count_close++;
        } else if (check_operations(i, str) && i == lenght - 1) {
            flag = 0;
        } else if (check_operats(i, str) && check_operats(i + 1, str)) {
            flag = 0;
        } else if ((str[i] < 40 || str[i] > 57) && str[i] != 's' && str[i] != 'c' && str[i] != 't' &&
                   str[i] != 'k' && str[i] != '$' && str[i] != 'l' && str[i] != ' ' && str[i] != 'x') {
            flag = 0;
        }
    }
    if (count_open != count_close) {
        flag = 0;
    }
    return flag;
}
