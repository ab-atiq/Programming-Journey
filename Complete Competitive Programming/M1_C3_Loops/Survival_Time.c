/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/FIZZBUZZ23_2

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n_buns, x_per_person_needs, D;
        scanf("%d %d %d", &n_buns, &x_per_person_needs, &D);
        int total_person_needs = x_per_person_needs * 5;
        int max_day_with_buns = n_buns / total_person_needs; // 0/total_person_needs = 0

        printf("%d\n", max_day_with_buns + D);
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, x, d;
        scanf("%d %d %d", &n, &x, &d);

        int y = 5 * x;

        int s = n / y;

        int ans = s + d;

        printf("%d\n", ans);
    }

    return 0;
}