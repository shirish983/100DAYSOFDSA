#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = MAX/2;
        deque[front] = x;
    } else {
        deque[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = MAX/2;
        deque[rear] = x;
    } else {
        deque[++rear] = x;
    }
}

void pop_front() {
    if (empty()) return;
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) return;
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front() {
    if (empty()) return -1;
    return deque[front];
}

int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (empty()) return;
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(op, "clear") == 0) {
            clear();
        }
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(op, "sort") == 0) {
            sort();
        }
    }

    display();
    return 0;
}
