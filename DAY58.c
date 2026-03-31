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

struct Node* build(int* pre, int* in, int preStart, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(pre[preStart]);

    int mid = inStart;
    while (in[mid] != pre[preStart])
        mid++;

    int leftSize = mid - inStart;

    root->left  = build(pre, in, preStart + 1,            inStart,  mid - 1);
    root->right = build(pre, in, preStart + 1 + leftSize, mid + 1,  inEnd);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int pre[100], in[100];

    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    struct Node* root = build(pre, in, 0, 0, n - 1);

    postorder(root);
    printf("\n");
    return 0;
}
