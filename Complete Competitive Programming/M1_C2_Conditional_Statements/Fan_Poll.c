/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/FIZZBUZZ2301
#include <stdio.h>
int main()
{
    int d, r, k;
    scanf("%d %d %d", &d, &r, &k);
    if (d > r && d > k)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}