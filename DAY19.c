#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int arr[100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int minSum = abs(arr[0] + arr[1]);
    int x = arr[0], y = arr[1];

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = abs(arr[i] + arr[j]);
            if(sum < minSum)
            {
                minSum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}
