/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://lightoj.com/problem/discovering-permutations

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n, k;
        cin >> n >> k;

        cout << "Case " << i << ":\n";
        // cout << s.substr(0, n) << "\n"; // n characters from the string
        string sub = s.substr(0, n);
        do
        {
            cout << sub << "\n";
        } while (next_permutation(sub.begin(), sub.end()) && --k);
    }
    return 0;
}