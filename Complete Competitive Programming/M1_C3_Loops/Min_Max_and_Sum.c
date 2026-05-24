/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_D

#include <stdio.h>
int main()
{
    int n, x, min = 1000001, max = -1000001;
    long long int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x < min)
        {
            min = x;
        }
        if (x > max)
        {
            max = x;
        }
        sum += x;
    }
    printf("%d %d %lld\n", min, max, sum);
    return 0;
}