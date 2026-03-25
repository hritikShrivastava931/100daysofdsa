#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node
{
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->hd = 0;
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

void verticalOrder(struct Node* root)
{
    if(root == NULL)
        return;

    int map[MAX][MAX];
    int count[MAX] = {0};

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            map[i][j] = -1;
        }
    }

    int offset = MAX / 2;

    struct Node* queue[MAX];
    int hdQueue[MAX];

    int front = 0;
    int rear = 0;

    root->hd = 0;

    queue[rear] = root;
    hdQueue[rear] = 0;
    rear++;

    int minHD = 0;
    int maxHD = 0;

    while(front < rear)
    {
        struct Node* current = queue[front];
        int hd = hdQueue[front];
        front++;

        int index = hd + offset;

        map[index][count[index]] = current->data;
        count[index]++;

        if(hd < minHD)
            minHD = hd;

        if(hd > maxHD)
            maxHD = hd;

        if(current->left != NULL)
        {
            queue[rear] = current->left;
            hdQueue[rear] = hd - 1;
            rear++;
        }

        if(current->right != NULL)
        {
            queue[rear] = current->right;
            hdQueue[rear] = hd + 1;
            rear++;
        }
    }

    for(int i = minHD; i <= maxHD; i++)
    {
        int index = i + offset;

        for(int j = 0; j < count[index]; j++)
        {
            printf("%d ", map[index][j]);
        }
        printf("\n");
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

    verticalOrder(root);

    return 0;
}