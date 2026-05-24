/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc303/tasks/abc303_a

#include <bits/stdc++.h>
using namespace std;

bool similar(char a, char b)
{
    if (a == b)
        return true;
    if ((a == '1' && b == 'l') || (a == 'l' && b == '1'))
        return true;
    if ((a == '0' && b == 'o') || (a == 'o' && b == '0'))
        return true;
    return false;
}

int main()
{
    int N;
    string S, T;
    cin >> N >> S >> T;

    for (int i = 0; i < N; i++)
    {
        if (!similar(S[i], T[i]))
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
