#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->val);
        if (node->left)  queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left        = newNode(9);
    root->right       = newNode(20);
    root->right->left  = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");
    return 0;
}
```

**Output:**
```
Level Order: 3 9 20 15 7
