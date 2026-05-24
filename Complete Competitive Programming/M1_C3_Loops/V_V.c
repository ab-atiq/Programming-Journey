/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://vjudge.net/contest/761326#problem/V

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int a1, a2, b1, b2;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        int res = (a1 + b1) - (a2 + b2);
        if (res >= 0)
        {
            printf("NO\n"); // not surplus
        }
        else
        {
            printf("YES\n"); // surplus
        }
    }
    return 0;
}