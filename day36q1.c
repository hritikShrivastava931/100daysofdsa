#include <stdio.h>

#define MAX 100

int queue[MAX];

int front = 0;

int rear = -1;

int size = 0;

void enqueue(int x,int n)
{
rear = (rear + 1) % n;

queue[rear] = x;

size++;
}

void dequeue(int n)
{
if(size > 0)
{
front = (front + 1) % n;

size--;
}
}

void display(int n)
{
int i;

int count = size;

i = front;

while(count > 0)
{
printf("%d ",queue[i]);

i = (i + 1) % n;

count--;
}
}

int main()
{
int n;

int m;

scanf("%d",&n);

for(int i=0;i<n;i++)
{
int x;

scanf("%d",&x);

enqueue(x,n);
}

scanf("%d",&m);

for(int i=0;i<m;i++)
{
dequeue(n);
}

display(n);

return 0;
}
