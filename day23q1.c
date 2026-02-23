#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);

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

struct Node* mergeLists(struct Node* head1, struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* temp = NULL;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        result = head1;
        head1 = head1->next;
    }
    else
    {
        result = head2;
        head2 = head2->next;
    }

    temp = result;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;

    if (head2 != NULL)
        temp->next = head2;

    return result;
}

void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    struct Node* mergedHead = mergeLists(head1, head2);

    printList(mergedHead);

    return 0;
}