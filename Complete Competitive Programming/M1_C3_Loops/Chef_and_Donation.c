/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/DNATION

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", y - x);
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        int extra = y - x;

        printf("%d\n", extra);
    }

    return 0;
}