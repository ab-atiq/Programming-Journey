/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/NEWSPAPER
#include <stdio.h>
int main()
{
    int x_page;
    scanf("%d", &x_page);
    if (8 <= x_page && x_page <= 10) // if (x_page >= 8)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}