/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1352/problem/A

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int num;
        scanf("%d", &num);
        int round_numbers[10];
        int count = 0;
        int place = 1;
        while (num > 0)
        {
            int digit = num % 10;
            if (digit != 0)
            {
                round_numbers[count] = digit * place;
                count++;
            }
            num /= 10;
            place *= 10;
        }
        printf("%d\n", count);
        for (int i = 0; i < count; i++)
        {
            printf("%d ", round_numbers[i]);
        }
        printf("\n");
    }
    return 0;
}

// cps
#include <stdio.h>
#include <limits.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int count = 0;

        int m = n; // copy of n
        while (m > 0)
        {
            int last_digit = m % 10;
            m /= 10;

            if (last_digit > 0) // only count non-zero digits for round numbers
            {
                count++;
            }
        }

        printf("%d\n", count);

        int p = 1;

        while (n > 0)
        {
            int last_digit = n % 10;
            n /= 10;

            if (last_digit != 0)
            {
                printf("%d ", last_digit * p);
            }

            p *= 10;
        }
        printf("\n");
    }

    return 0;
}