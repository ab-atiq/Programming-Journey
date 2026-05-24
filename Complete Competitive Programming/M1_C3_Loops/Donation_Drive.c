/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/DONDRIVE

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        printf("%d\n", n - x);
    }
    return 0;
}