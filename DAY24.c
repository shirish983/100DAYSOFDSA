#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, key, x;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *prev = NULL, *curr = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    curr = head;

    if (head != NULL && head->data == key)
    {
        head = head->next;
    }
    else
    {
        while (curr != NULL && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL)
        {
            prev->next = curr->next;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
