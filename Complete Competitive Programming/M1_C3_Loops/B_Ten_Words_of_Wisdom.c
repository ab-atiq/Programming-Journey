/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1850/problem/B

#include <stdio.h>
#include <limits.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, winner_response = -1;
        scanf("%d", &n);
        int max_response = INT_MIN, max_quality = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > 10)
            {
                continue; // skip this response as it doesn't meet the criteria
            }
            if (max_quality < b)
            {
                max_quality = b;
                max_response = a;
                winner_response = i + 1; // 1-based index
            }
            else if (max_quality == b)
            {
                if (max_response < a)
                {
                    max_response = a;
                    winner_response = i + 1; // 1-based index
                }
            }
        }
        printf("%d\n", winner_response);
    }
    return 0;
}

// thought max_quality is unique so does not need to check for max_response.
#include <stdio.h>
#include <limits.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n, winner_response = -1;
        scanf("%d", &n);
        int max_quality = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > 10)
            {
                continue; // skip this response as it doesn't meet the criteria
            }
            if (max_quality < b)
            {
                max_quality = b;
                winner_response = i + 1; // 1-based index
            }
        }
        printf("%d\n", winner_response);
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

        int max_quality = INT_MIN;
        int response_number = 0;

        for (int i = 1; i <= n; i++)
        {
            int length, quality;
            scanf("%d %d", &length, &quality);

            if (length > 10)
            {
                continue;
            }

            if (quality > max_quality)
            {
                max_quality = quality;
                response_number = i;
            }
        }

        printf("%d\n", response_number);
    }

    return 0;
}