/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://atcoder.jp/contests/abc333/tasks/abc333_b

// wrong answer - This does not correctly compute the distances along a pentagon. For example, in a regular pentagon ABCDE, the distance from A to C is 2 (A → B → C), and from E to C is also 2 (E → D → C). But your ss_cal2 and tt_cal2 calculations only consider 'E' - letter + 1, which does not wrap around the pentagon properly.
// #include <stdio.h>
// int main()
// {
//     char s1, s2, t1, t2;
//     scanf("%c%c %c%c", &s1, &s2, &t1, &t2);
//     // printf("%c%c\n%c%c", s1, s2, t1, t2);

//     // solve like - ABCDE
//     if ((s1 == t1 && s2 == t2) || (s1 == t2 && s2 == t1))
//     {
//         printf(" Yes\n");
//     }
//     else
//     {
//         // make minimum s1
//         if (s1 > s2)
//         {
//             char temp = s1;
//             s1 = s2;
//             s2 = temp;
//         }
//         // make minimum t1
//         if (t1 > t2)
//         {
//             char temp = t1;
//             t1 = t2;
//             t2 = temp;
//         }
//         int ss_cal1 = s2 - s1;
//         int ss_cal2 = 'E' - s2 + 1;
//         int tt_cal1 = t2 - t1;
//         int tt_cal2 = 'E' - t2 + 1;
//         if (ss_cal1 == tt_cal1 || ss_cal1 == tt_cal2 || ss_cal2 == tt_cal1 || ss_cal2 == tt_cal2)
//         {
//             printf(" Yes\n");
//         }
//         else
//         {
//             printf(" No\n");
//         }
//     }

//     return 0;
// }

// right answer
// #include <stdio.h>
// #include <stdlib.h>

// int distance(char a, char b)
// {
//     int d = abs(a - b);
//     if (d > 2)
//         d = 5 - d; // wrap around the pentagon
//     return d;
// }

// int main()
// {
//     char s1, s2, t1, t2;
//     scanf("%c%c %c%c", &s1, &s2, &t1, &t2);

//     if (distance(s1, s2) == distance(t1, t2))
//     {
//         printf("Yes\n");
//     }
//     else
//     {
//         printf("No\n");
//     }

//     return 0;
// }

// my code

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s1, s2, t1, t2;
    scanf("%c%c %c%c", &s1, &s2, &t1, &t2); // warning on &
    // scanf("%c%c %c%c", s1, s2, t1, t2); // wrong answer when & not provided
    int dis_s = abs(s1 - s2);
    int dis_t = abs(t1 - t2);

    // minimize distance in pentagon
    if (dis_s > 2)
        dis_s = 5 - dis_s;
    if (dis_t > 2)
        dis_t = 5 - dis_t;

    if (dis_s == dis_t)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

// warning fixed
int main()
{
    char s1, s2, t1, t2;
    int _ = scanf("%c%c %c%c", &s1, &s2, &t1, &t2); // store the result
    (void)_;                                        // explicitly ignore it

    int dis_s = abs(s1 - s2);
    int dis_t = abs(t1 - t2);
    if (dis_s > 2)
        dis_s = 5 - dis_s;
    if (dis_t > 2)
        dis_t = 5 - dis_t;

    printf(dis_s == dis_t ? "Yes\n" : "No\n");
    return 0;
}
