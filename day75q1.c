#include <stdio.h>

int maxLenZeroSum(int arr[], int n)
{
    int sum = 0;
    int maxLen = 0;

    int prefix[1000];
    int index[1000];
    int size = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
        {
            maxLen = i + 1;
        }

        int found = 0;

        for(int j = 0; j < size; j++)
        {
            if(prefix[j] == sum)
            {
                int len = i - index[j];
                if(len > maxLen)
                {
                    maxLen = len;
                }
                found = 1;
                break;
            }
        }

        if(!found)
        {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return maxLen;
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

    int result = maxLenZeroSum(arr, n);

    printf("%d\n", result);

    return 0;
}