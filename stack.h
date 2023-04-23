
typedef struct stack {
    char c;
    struct stack *next;
} stack;

struct expres {
    double value;
    struct expres *next;
};

void push_expres(struct expres **head, double val);
double pop_expres(struct expres **head);
void destroy(struct expres *root);
void push(stack **root, char data);
char pop(stack **HEAD);