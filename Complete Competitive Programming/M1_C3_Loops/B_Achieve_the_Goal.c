/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc151/tasks/abc151_b?lang=en

#include <stdio.h>
int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    // solution - 1
    int required_score = (n * m) - sum;
    if (required_score > k)
        printf("-1\n");
    else if (required_score < 0)
        printf("0\n");
    else
        printf("%d\n", required_score);
    return 0;
}

//  solution - 2
#include <stdio.h>
int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    int min_res = (m * n) - sum;
    if (min_res <= k && min_res >= 0)
    {
        printf("%d", min_res);
    }
    else if (min_res < 0)
    {
        printf("0");
    }
    else
    {
        printf("-1");
    }
    return 0;
}

// cps
#include <stdio.h>
#include <limits.h>

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    int s = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int a;
        scanf("%d", &a);
        s += a;
    }

    int remaining = n * m - s;

    if (remaining > k)
    {
        printf("-1\n");
    }
    else
    {
        if (remaining < 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", remaining);
        }
    }

    return 0;
}