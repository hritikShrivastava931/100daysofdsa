#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
top = top + 1;
stack[top] = x;
}

void pop()
{
if(top == -1)
{
return;
}
top = top - 1;
}

void display()
{
int i;

for(i = top; i >= 0; i--)
{
printf("%d ", stack[i]);
}
}

int main()
{
int n;
int m;
int i;
int x;

scanf("%d",&n);

for(i = 0; i < n; i++)
{
scanf("%d",&x);
push(x);
}

scanf("%d",&m);

for(i = 0; i < m; i++)
{
pop();
}

display();

return 0;
}