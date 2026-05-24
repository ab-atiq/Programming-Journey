/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc329/tasks/abc329_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i + 1 != s.size()) cout << " ";  // no space after last char
    }

    return 0;
}
