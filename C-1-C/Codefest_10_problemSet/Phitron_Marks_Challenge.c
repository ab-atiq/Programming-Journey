#include <stdio.h>

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int sum = 0;

    for (int i = 1; i < N; i++)
    {
        int marks;
        scanf("%d", &marks);
        sum += marks;
    }

    int required = (N * K) - sum;

    if (required <= 0)
    {
        printf("0\n");
    }
    else if (required <= M)
    {
        printf("%d\n", required);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}