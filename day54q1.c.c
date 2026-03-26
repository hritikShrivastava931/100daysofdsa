#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n)
    {
        struct Node* current = queue[front++];

        if(arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

void zigzagTraversal(struct Node* root)
{
    if(root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while(front < rear)
    {
        int size = rear - front;

        int level[MAX];

        for(int i = 0; i < size; i++)
        {
            struct Node* current = queue[front++];

            if(leftToRight)
            {
                level[i] = current->data;
            }
            else
            {
                level[size - 1 - i] = current->data;
            }

            if(current->left != NULL)
            {
                queue[rear++] = current->left;
            }

            if(current->right != NULL)
            {
                queue[rear++] = current->right;
            }
        }

        for(int i = 0; i < size; i++)
        {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}