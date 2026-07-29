// https://www.codechef.com/problems/PASSCHAIN

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        // solution - 1
        // int max_pass_possible = (n - 1) / k; // floor division, n-1 because ball pass start from 1st person
        // int ball_present_at_end = 1 + max_pass_possible * k;
        // cout << ball_present_at_end << "\n";

        // solution - 2 - using loop
        // int start = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (start + k <= n)
        //         start += k;
        //     else
        //         break;
        // }
        // cout << start << endl;

        // optimize code
        int start;
        for (start = 1; start <= (n - k); start += k)
        {
            // automatically point to last player who get ball
        }
        cout << start << endl;
    }
    return 0;
}