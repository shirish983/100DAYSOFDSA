#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Find LCA in Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If either node matches
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    // If both sides return non-null → this is LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise return non-null child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n, n1, n2;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n, 0);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
