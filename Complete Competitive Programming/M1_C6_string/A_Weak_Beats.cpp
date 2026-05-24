/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc323/tasks/abc323_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    bool ok = true;

    for (int i = 1; i < 16; i += 2)
    { // even positions (1-indexed)
        if (S[i] != '0')
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
