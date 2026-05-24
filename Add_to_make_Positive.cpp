/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/START217D/problems/ADDPOS

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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            // if (x < 0)
            sum += x;
        }
        // abs
        // sum = abs(sum);
        if (sum >= 0)
        {
            cout << 0 << endl;
        }
        else
        {
            // ceiling value of sum/n
            // cout << (sum + n - 1) / n << endl;
            // here sum is negative
            cout << (-sum + n - 1) / n << endl;
        }
    }
    return 0;
}
/* 
// chatgpt
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }

        // If sum is already non-negative, X = 0
        if (sum >= 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            // Minimum X such that sum + N*X >= 0
            long long X = (-sum + N - 1) / N; // ceil division
            cout << X << '\n';
        }
    }

    return 0;
}
 */