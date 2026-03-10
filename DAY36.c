#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    if (q->front == NULL) {
        q->front = q->rear = temp;
        temp->next = q->front;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    q->rear->next = q->front;
}

void dequeue(Queue* q) {
    if (q->front == NULL) return;

    Node* temp = q->front;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
}

void display(Queue* q) {
    if (q->front == NULL) return;

    Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    int n, m, x;

    Queue q;
    q.front = q.rear = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    return 0;
}
