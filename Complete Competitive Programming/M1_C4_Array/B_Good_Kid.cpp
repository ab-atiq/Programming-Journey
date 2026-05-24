/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1873/problem/B

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        // minimum element index value increase by 1
        // int min_val = INT_MAX, min_idx = -1;
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     if (arr[i] < min_val)
        //     {
        //         min_val = arr[i];
        //         min_idx = i;
        //     }
        // }
        // arr[min_idx] = arr[min_idx] + 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        arr[0] += 1;

        // product calculation
        int mul = 1;
        for (int i = 0; i < n; i++)
        {
            mul *= arr[i];
        }
        cout << mul << endl;
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
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // every value increase by 1 then maximum product calculation
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i]++;
            int m = 1;
            for (int j = 0; j < n; j++)
            {
                m *= arr[j];
            }
            if (m > ans)
            {
                ans = m;
            }
            arr[i]--;
        }
        printf("%d\n", ans);
    }

    return 0;
}