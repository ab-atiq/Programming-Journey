/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc233/tasks/abc233_b?lang=en

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

// cps
#include <stdio.h>
#include <string.h>

int main()
{

    int l, r;
    scanf("%d%d", &l, &r);

    l--, r--;

    char s[100001];
    scanf("%s", s);

    int n = strlen(s);

    //[0,l-1]
    for (int i = 0; i <= l - 1; i++)
    {
        printf("%c", s[i]);
    }

    //[r,l]
    for (int i = r; i >= l; i--)
    {
        printf("%c", s[i]);
    }

    //[r+1,n-1]
    for (int i = r + 1; i < n; i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");

    return 0;
}