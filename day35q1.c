#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
struct node *newnode;

newnode = (struct node*)malloc(sizeof(struct node));

newnode->data = value;

newnode->next = NULL;

if(front == NULL)
{
front = newnode;
rear = newnode;
}
else
{
rear->next = newnode;
rear = newnode;
}
}

void display()
{
struct node *temp;

temp = front;

while(temp != NULL)
{
printf("%d ", temp->data);

temp = temp->next;
}
}

int main()
{
int n;

int x;

scanf("%d", &n);

for(int i = 0; i < n; i++)
{
scanf("%d", &x);

enqueue(x);
}

display();

return 0;
}