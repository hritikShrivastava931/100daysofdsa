#include <stdio.h>

#define EMPTY -1

int hash(int key, int m)
{
    return key % m;
}

void insert(int table[], int key, int m)
{
    int i = 0;
    int index;

    while (i < m)
    {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY)
        {
            table[index] = key;
            return;
        }

        i++;
    }
}

int search(int table[], int key, int m)
{
    int i = 0;
    int index;

    while (i < m)
    {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY)
        {
            return 0;
        }

        if (table[index] == key)
        {
            return 1;
        }

        i++;
    }

    return 0;
}

int main()
{
    int m;
    int q;

    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    for (int i = 0; i < m; i++)
    {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < q; i++)
    {
        scanf("%s %d", operation, &key);

        if (operation[0] == 'I')
        {
            insert(table, key, m);
        }
        else if (operation[0] == 'S')
        {
            if (search(table, key, m))
            {
                printf("FOUND\n");
            }
            else
            {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}