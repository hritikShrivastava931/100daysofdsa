#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n)
{
    if (n == 0) return NULL;

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL)
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

int isMirror(struct Node* t1, struct Node* t2)
{
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    if (t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root)
{
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}