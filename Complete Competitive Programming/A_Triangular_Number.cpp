/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc435/tasks/abc435_a

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // solution - 1
    // int sum = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     sum += i;
    // }
    // cout << sum << endl;
    // solution - 2
    cout << n * (n + 1) / 2 << endl;
    return 0;
}