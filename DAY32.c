#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n;
    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    int m;
    scanf("%d", &m);

    // Pop m elements
    for (int i = 0; i < m; i++) {
        if (top == -1) break;
        pop();
    }

    // Print remaining elements (top to bottom)
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
