#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* queue[100];

int front = 0;
int rear = 0;

void enqueue(struct Node* node)
{
    queue[rear] = node;
    rear++;
}

struct Node* dequeue()
{
    struct Node* temp = queue[front];
    front++;
    return temp;
}

int isEmpty()
{
    if(front == rear)
    {
        return 1;
    }
    return 0;
}

void levelOrder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }

    enqueue(root);

    while(!isEmpty())
    {
        struct Node* temp = dequeue();

        printf("%d ", temp->data);

        if(temp->left != NULL)
        {
            enqueue(temp->left);
        }

        if(temp->right != NULL)
        {
            enqueue(temp->right);
        }
    }
}

int main()
{
    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}