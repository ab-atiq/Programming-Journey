/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1669/problem/A

#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int rating;
        scanf("%d", &rating);
        if (rating >= 1900)
            printf("Division 1\n");
        else if (rating >= 1600) // else if (rating <= 1899 && rating >= 1600)
            printf("Division 2\n");
        else if (rating >= 1400) // else if (rating <= 1599 && rating >= 1400)
            printf("Division 3\n");
        else // else if (rating <= 1399)
            printf("Division 4\n");
    }
    return 0;
}