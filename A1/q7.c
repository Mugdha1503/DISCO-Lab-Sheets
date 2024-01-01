#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < (1 << n); i++)
    {
        int summ = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                summ += arr[j];
        }
        if (summ == k)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j)) != 0)
                    printf("%d ", arr[j]);
            }
            return 0;
        }
    }
}
