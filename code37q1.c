#include <stdio.h>
#include <string.h>

int pq[100];
int n = 0;

void insert(int x)
{
pq[n] = x;
n++;
}

int findMin()
{
if(n == 0)
{
return -1;
}

int minIndex = 0;

for(int i = 1; i < n; i++)
{
if(pq[i] < pq[minIndex])
{
minIndex = i;
}
}

return minIndex;
}

void delete()
{
int index = findMin();

if(index == -1)
{
printf("-1\n");
return;
}

printf("%d\n", pq[index]);

for(int i = index; i < n - 1; i++)
{
pq[i] = pq[i + 1];
}

n--;
}

void peek()
{
int index = findMin();

if(index == -1)
{
printf("-1\n");
}
else
{
printf("%d\n", pq[index]);
}
}

int main()
{
int N;

scanf("%d", &N);

for(int i = 0; i < N; i++)
{
char op[10];
scanf("%s", op);

if(strcmp(op, "insert") == 0)
{
int x;
scanf("%d", &x);
insert(x);
}

else if(strcmp(op, "delete") == 0)
{
delete();
}

else if(strcmp(op, "peek") == 0)
{
peek();
}
}

return 0;
}