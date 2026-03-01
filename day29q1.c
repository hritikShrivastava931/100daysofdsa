#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n;
    scanf("%d", &n);

    if(n <= 0)
    {
        return 0;
    }

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    int value;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    if(head == NULL || head->next == NULL || k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    struct Node* last = head;
    int length = 1;

    while(last->next != NULL)
    {
        last = last->next;
        length++;
    }

    k = k % length;

    if(k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    last->next = head;

    int steps = length - k;
    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
    {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}