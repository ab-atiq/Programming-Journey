#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A[100];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int current = A[0];

    for (int i = 1; i < N; i++)
    {
        if (A[i] > current)
        {
            current = A[i];
        }
        else
        {
            break;
        }
    }

    printf("%d\n", current);

    return 0;
}