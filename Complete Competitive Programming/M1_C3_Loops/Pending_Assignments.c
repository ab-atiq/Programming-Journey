/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/ASSIGNMNT

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int total_times_for_assignments = x * y;
        int minitues_from_day = 24 * 60 * z;
        if (total_times_for_assignments <= minitues_from_day)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
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
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        int total = z * 24 * 60;
        int req = x * y;

        if (total >= req)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}