#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection value
void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            printf("%d", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *newNode = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    findIntersection(head1, head2);

    return 0;
}
