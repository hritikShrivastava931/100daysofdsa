#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

struct Node* deleteFirstOccurrence(struct Node* head, int key)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data == key)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;

    while (current->next != NULL && current->next->data != key)
    {
        current = current->next;
    }

    if (current->next != NULL)
    {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}

void printList(struct Node* head)
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        append(&head, value);
    }

    int key;
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printList(head);

    return 0;
}