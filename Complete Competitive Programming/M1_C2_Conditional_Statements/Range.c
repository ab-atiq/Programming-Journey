/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_B

#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    // option - 1
    // if (b < c)
    // {
    //     if (a < b)
    //     {
    //         printf("Yes\n");
    //     }
    //     else
    //     {
    //         printf("No\n");
    //     }
    // }
    // else
    // {
    //     printf("No\n");
    // }
    
    // option - 2
    if (a < b && b < c)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}