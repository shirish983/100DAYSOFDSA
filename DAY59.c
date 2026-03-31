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

struct Node* build(int* in, int* post, int inStart, int inEnd, int postEnd) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(post[postEnd]);

    int mid = inStart;
    while (in[mid] != post[postEnd])
        mid++;

    int leftSize = mid - inStart;

    root->left  = build(in, post, inStart,  mid - 1, postEnd - 1 - (inEnd - mid));
    root->right = build(in, post, mid + 1,  inEnd,   postEnd - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[100], post[100];

    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    struct Node* root = build(in, post, 0, n - 1, n - 1);

    preorder(root);
    printf("\n");
    return 0;
}
