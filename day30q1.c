#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *head = NULL;

void insert(int c, int e)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        struct node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

void display()
{
    struct node *p = head;

    while(p != NULL)
    {
        if(p->exp == 0)
            printf("%d", p->coeff);
        else if(p->exp == 1)
            printf("%dx", p->coeff);
        else
            printf("%dx^%d", p->coeff, p->exp);

        if(p->next != NULL)
            printf(" + ");

        p = p->next;
    }
}

int main()
{
    int n,c,e;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&c,&e);
        insert(c,e);
    }

    display();

    return 0;
}