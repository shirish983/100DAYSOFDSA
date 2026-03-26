#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct Node* queue[100];
    int front = 0, rear = 0;
    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[100];

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];
            int idx = leftToRight ? i : (size - 1 - i);
            level[idx] = node->data;
            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    zigzag(root);
    return 0;
}
