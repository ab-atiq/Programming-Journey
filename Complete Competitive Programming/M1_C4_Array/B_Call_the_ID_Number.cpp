/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc293/tasks/abc293_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1], fre[n + 1];
    for (int i = 0; i <= n; i++)
    {
        fre[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (fre[i] == 0) // if i'th ID not called yet
        {
            fre[arr[i]]++; // then call the i'th ID person
        }
    }
    // count how many ID numbers are not called
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fre[i] == 0)
        {
            // cout << i << " ";
            cnt++;
        }
    }
    cout << cnt << "\n";
    // print the ID numbers which are not called
    for (int i = 1; i <= n; i++)
    {
        if (fre[i] == 0)
        {
            cout << i << " ";
            // cnt++;
        }
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int F[n + 1];

    for (int i = 1; i <= n; i++)
    {
        F[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (F[i] == 0)
        {
            F[arr[i]] = 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (F[i] == 0)
        {
            ans++;
        }
    }

    printf("%d\n", ans);

    for (int i = 1; i <= n; i++)
    {
        if (F[i] == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}