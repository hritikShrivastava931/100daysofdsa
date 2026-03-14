#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0;
int rear = -1;

int top = -1;

void enqueue(int x)
{
rear++;
queue[rear] = x;
}

int dequeue()
{
int x;
x = queue[front];
front++;
return x;
}

void push(int x)
{
top++;
stack[top] = x;
}

int pop()
{
int x;
x = stack[top];
top--;
return x;
}

int main()
{
int n;
scanf("%d",&n);

for(int i = 0 ; i < n ; i++)
{
int x;
scanf("%d",&x);
enqueue(x);
}

for(int i = front ; i <= rear ; i++)
{
int x;
x = dequeue();
push(x);
}

while(top != -1)
{
int x;
x = pop();
enqueue(x);
}

for(int i = front ; i <= rear ; i++)
{
printf("%d ",queue[i]);
}

return 0;
}