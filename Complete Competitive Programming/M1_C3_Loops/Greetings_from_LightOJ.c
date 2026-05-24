/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://lightoj.com/problem/greetings-from-lightoj

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int merge = a + b;
        printf("Case %d: %d\n", t, merge);
    }
    return 0;
}

// solution - 2
// #include <stdio.h>
// int main()
// {
//     int tc, a, b, i=1;
//     scanf("%d", &tc);
//     while (tc--)
//     {
//         scanf("%d %d", &a, &b);
//         int merge = a + b;
//         printf("Case %d: %d\n", i++, merge);
//     }
//     return 0;
// }

// solution - 3
// #include <stdio.h>
// int main()
// {
//     int tc, a, b, cpy_tc;
//     scanf("%d", &tc);
//     cpy_tc = tc;
//     while (tc--)
//     {
//         scanf("%d %d", &a, &b);
//         int merge = a + b;
//         printf("Case %d: %d\n", cpy_tc - tc, merge);
//     }
//     return 0;
// }