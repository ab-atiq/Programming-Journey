/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_B

// solution approch - 1
// #include <stdio.h>
// int main()
// {
//     int x;
//     scanf("%d", &x);
//     for (int i = 1;; i++)
//     {
//         if (x == 0)
//         {
//             break;
//         }
//         printf("Case %d: %d\n", i, x);
//         scanf("%d", &x);
//     }
//     return 0;
// }

// solution approch - 2
// #include <stdio.h>
// int main()
// {
//     int x;
//     for (int i = 1;; i++)
//     {
//         scanf("%d", &x);
//         if (x == 0)
//         {
//             break;
//         }
//         printf("Case %d: %d\n", i, x);
//     }
//     return 0;
// }

// solution approch - 3
// #include <stdio.h>
// int main()
// {
//     int x, i = 1;
//     while (1)
//     {
//         scanf("%d", &x);
//         if (x == 0)
//         {
//             break;
//         }
//         printf("Case %d: %d\n", i, x);
//         i++;
//     }
//     return 0;
// }

// solution approch - 7 - do while loop
// #include <stdio.h>
// int main()
// {
//     int x, i = 1;
//     do
//     {
//         scanf("%d", &x);
//         if (x != 0)
//         {
//             printf("Case %d: %d\n", i, x);
//             i++;
//         }
//         // else
//         // {
//         //     break;
//         // }
//     } while (x != 0);
//     return 0;
// }

// solution approch - 4 - end of file and x!=0 check
// #include <stdio.h>
// int main()
// {
//     int x, i = 1;
//     while (scanf("%d", &x), x != 0)
//     {
//         printf("Case %d: %d\n", i, x);
//         i++;
//     }
//     return 0;
// }

// solution approch - 5
// #include <stdio.h>
// int main()
// {
//     int x, i = 1;
//     while (scanf("%d", &x) != EOF)
//     {
//         if (x == 0)
//         {
//             break;
//         }
//         printf("Case %d: %d\n", i, x);
//         i++;
//     }
//     return 0;
// }

// solution approch - 6
// #include <stdio.h>
// int main()
// {
//     int x, i = 1;
//     while (1)
//     {
//         if (scanf("%d", &x) == EOF || x == 0)
//         {
//             break;
//         }
//         printf("Case %d: %d\n", i, x);
//         i++;
//     }
//     return 0;
// }

// solution approch - 8 -
#include <stdio.h>
int main()
{
    int x, i = 1;
    // while (scanf("%d", &x) != EOF)
    // while (scanf("%d", &x), x != 0)
    while (scanf("%d", &x))
    {
        if (x == 0)
        {
            break;
        }
        printf("Case %d: %d\n", i++, x);
    }
    return 0;
}