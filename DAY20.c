#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum = 0;
        for (int j = i; j < n; j++)
        {
            prefixSum += arr[j];
            if (prefixSum == 0)
                count++;
        }
    }

    printf("%d", count);
    return 0;
}
