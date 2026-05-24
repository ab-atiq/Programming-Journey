/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc315/tasks/abc315_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    string ans = "";
    for (char c : S)
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        {
            ans += c;
        }
    }

    cout << ans << endl;
    return 0;
}
