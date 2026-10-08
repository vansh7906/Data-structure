#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top < MAX - 1) stack[++top] = item;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '#';
}

char peek() {
    if (top >= 0) return stack[top];
    return '#';
}

int is_alphanumeric(char ch) {
    return ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9'));
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (is_alphanumeric(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX];

    infixToPostfix(infix, postfix);
    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
