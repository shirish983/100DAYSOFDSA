#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[rear++] = curr->left;
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[rear++] = curr->right;
            }
            i++;
        }
    }

    return root;
}

void inorder(struct TreeNode* root, int* first) {
    if (root == NULL) return;
    inorder(root->left, first);
    if (*first) printf(" ");
    printf("%d", root->val);
    *first = 1;
    inorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    int first = 0;
    inorder(root, &first);
    printf("\n");

    return 0;
}
```

**How it works:**

**Build Tree (Level-order):**
- Use a queue to track parent nodes
- For each node, assign next two values as left and right children
- Skip (`-1` = NULL) but still consume the slot

**For input `1 2 3 4 5 -1 6`:**
```
        1
       / \
      2   3
     / \ / \
    4  5 N  6
