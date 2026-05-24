/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc311/tasks/abc311_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    bool a = false, b = false, c = false;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'A')
            a = true;
        if (S[i] == 'B')
            b = true;
        if (S[i] == 'C')
            c = true;

        if (a && b && c)
        {
            cout << i + 1 << endl; // index is 1-based
            return 0;
        }
    }
}
