/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/SPCP1
#include <stdio.h>
int main()
{
    int w, h, chef_w = 60, chef_h = 130;
    scanf("%d %d", &w, &h);
    if (chef_w <= w && chef_h >= h)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}