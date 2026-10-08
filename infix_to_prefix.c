#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

int main() {
    char infix[100], prefix[100], ch, temp;
    int i, j = 0, n;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    n = strlen(infix);

    for (i = 0; i < n / 2; i++) {
        temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }

    for (i = 0; i < n; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (i = 0; i < n; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) > priority(ch))
                prefix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';

    n = strlen(prefix);

    for (i = 0; i < n / 2; i++) {
        temp = prefix[i];
        prefix[i] = prefix[n - i - 1];
        prefix[n - i - 1] = temp;
    }

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
