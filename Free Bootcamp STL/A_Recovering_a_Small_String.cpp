/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/problemset/problem/1931/A

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            for (char k = 'a'; k <= 'z'; k++)
            {
                int sum = 0;
                sum += (i - 'a' + 1);
                sum += (j - 'a' + 1);
                sum += (k - 'a' + 1);
                if (sum == n)
                {
                    cout << i << j << k << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}