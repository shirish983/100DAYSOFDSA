#include <stdio.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Queue structure
int queue[MAX];
int front = 0, rear = -1;

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

// Queue operations
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, i;

    scanf("%d", &n);

    // Input queue elements
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    for(i = 0; i < n; i++) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Move stack elements back to queue
    while(top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
