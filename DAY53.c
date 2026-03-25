#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
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

// Storage for vertical order
int vertical[2 * MAX][MAX];
int count[2 * MAX];

// Traverse and store nodes
void findVertical(struct Node* root, int hd) {
    if (root == NULL)
        return;

    int index = hd + MAX; // shift to avoid negative index

    vertical[index][count[index]++] = root->data;

    findVertical(root->left, hd - 1);
    findVertical(root->right, hd + 1);
}

// Print result
void printVertical() {
    for (int i = 0; i < 2 * MAX; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", vertical[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    findVertical(root, 0);

    printVertical();

    return 0;
}
