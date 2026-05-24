// https://codeforces.com/problemset/problem/1832/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int l = 0, r = n - 1;

        // Perform exactly k operations
        while (k--)
        {
            // If removing two minimums costs less than removing the maximum
            if (l + 1 <= r && a[l] + a[l + 1] < a[r])
            {
                l += 2; // remove two smallest
            }
            else
            {
                r--; // remove largest
            }
        }

        long long ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans += a[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
