/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1669/problem/B

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
        int arr[n], fre[n + 1];
        for (int i = 1; i <= n; i++)
        {
            fre[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            fre[arr[i]]++;
        }
        // update frequency into ans
        // int ans = -1;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (fre[i] >= 3)
        //     {
        //         ans = i;
        //         break;
        //     }
        // }
        // cout << ans << endl;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (fre[i] >= 3)
            {
                cout << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}


// cps
#include<stdio.h>

int main() {

    int t;
    scanf("%d", & t);

    while (t--) {
        int n;
        scanf("%d", & n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", & arr[i]);
        }

        int F[n + 1];

        for (int i = 1; i <= n; i++) {
            F[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            F[arr[i]]++;
        }

        int ans = -1;

        for (int i = 1; i <= n; i++) {
            if (F[i] >= 3) {
                ans = i;
                break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}