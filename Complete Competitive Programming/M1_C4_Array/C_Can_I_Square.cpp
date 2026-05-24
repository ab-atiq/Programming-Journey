/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1915/problem/C

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        int flag = 0;
        // check if sum is perfect square
        // for (int i = 1; i <= 1000; i++)
        // {
        //     if (i * i == sum)
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }

        // optimized - TLE
        // for (long long int i = 1; i * i <= sum; i++)
        // {
        //     if (i * i == sum)
        //     {
        //         flag = 1;
        //         break;
        //     }
        // }
        // if (flag)
        //     cout << "YES\n";
        // else
        //     cout << "NO\n";

        // long long int a = round(sqrt(sum * 1.0)); // correct
        long long int a = sqrt(sum); // correct
        if (a * a == sum)
            cout << "YES\n";
        else
            cout << "NO\n";
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
        int n;
        scanf("%d", &n);

        int arr[n];
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        long long a = round(sqrt(sum * 1.0));
        if (a * a == sum)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}