/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C
// #include <stdio.h>
// int main()
// {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     if (a < b && a < c)
//     {
//         if (b <= c)
//         {
//             printf("%d %d %d\n", a, b, c);
//         }
//         else
//         {
//             printf("%d %d %d\n", a, c, b);
//         }
//     }
//     else if (b < a && b < c)
//     {
//         if (a < c)
//         {
//             printf("%d %d %d\n", b, a, c);
//         }
//         else
//         {
//             printf("%d %d %d\n", b, c, a);
//         }
//     }
//     else
//     {
//         if (b < a)
//         {
//             printf("%d %d %d\n", c, b, a);
//         }
//         else
//         {
//             printf("%d %d %d\n", c, a, b);
//         }
//     }
//     return 0;
// }

// solve using - min and max value update
// #include <stdio.h>
// int main()
// {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     /*
//      * Optimized: sort three integers with at most 3 comparisons using
//      * a few conditional swaps. This keeps the I/O identical but is
//      * shorter and easier to reason about.
//      */
//     int tmp;
//     if (a > b)
//     {
//         tmp = a;
//         a = b;
//         b = tmp;
//     } /* now a <= b */
//     if (a > c)
//     {
//         tmp = a;
//         a = c;
//         c = tmp;
//     } /* now a is min */
//     if (b > c)
//     {
//         tmp = b;
//         b = c;
//         c = tmp;
//     } /* now b <= c */

//     printf("%d %d %d\n", a, b, c);
//     return 0;
// }

// solution using array
/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
#include <stdio.h>
#include <algorithm>
int main()
{
    int arr[3];
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    // sort
    std::sort(arr, arr + 3);

    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}


// cps
#include<stdio.h>

int main() {

    int a, b, c;
    scanf("%d%d%d", & a, & b, & c);

    if (a > b) {
        if (c < b) {
            printf("%d %d %d\n", c, b, a);
        } else if (c < a) {
            printf("%d %d %d\n", b, c, a);
        } else {
            printf("%d %d %d\n", b, a, c);
        }
    } else {
        if (c < a) {
            printf("%d %d %d\n", c, a, b);
        } else if (c < b) {
            printf("%d %d %d\n", a, c, b);
        } else {
            printf("%d %d %d\n", a, b, c);
        }
    }

    return 0;
}