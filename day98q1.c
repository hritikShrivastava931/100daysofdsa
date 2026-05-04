#include <stdio.h>
#include <stdlib.h>

struct Interval
{
    int start;
    int end;
};

int compare(const void *a, const void *b)
{
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

void mergeIntervals(struct Interval arr[], int n)
{
    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval result[n];

    int index = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start <= result[index].end)
        {
            if (arr[i].end > result[index].end)
            {
                result[index].end = arr[i].end;
            }
        }
        else
        {
            index++;
            result[index] = arr[i];
        }
    }

    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

int main()
{
    struct Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}