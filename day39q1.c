#include<stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

void heapifyUp(int index)
{
while(index>0)
{
int parent=(index-1)/2;

if(heap[parent]>heap[index])
{
swap(&heap[parent],&heap[index]);
index=parent;
}
else
{
break;
}
}
}

void heapifyDown(int index)
{
while(2*index+1<size)
{
int left=2*index+1;
int right=2*index+2;
int smallest=left;

if(right<size && heap[right]<heap[left])
{
smallest=right;
}

if(heap[index]>heap[smallest])
{
swap(&heap[index],&heap[smallest]);
index=smallest;
}
else
{
break;
}
}
}

void insert(int x)
{
heap[size]=x;
heapifyUp(size);
size++;
}

int extractMin()
{
if(size<=0)
{
return -1;
}

int root=heap[0];

heap[0]=heap[size-1];

size--;

heapifyDown(0);

return root;
}

int peek()
{
if(size<=0)
{
return -1;
}

return heap[0];
}

int main()
{
int n;
scanf("%d",&n);

for(int i=0;i<n;i++)
{
char op[20];
scanf("%s",op);

if(op[0]=='i')
{
int x;
scanf("%d",&x);
insert(x);
}

else if(op[0]=='p')
{
printf("%d\n",peek());
}

else if(op[0]=='e')
{
printf("%d\n",extractMin());
}
}

return 0;
}