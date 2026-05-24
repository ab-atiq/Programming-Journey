/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc327/tasks/abc327_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    bool found = false;
    for (int i = 0; i + 1 < N; i++)
    {
        if ((S[i] == 'a' && S[i + 1] == 'b') ||
            (S[i] == 'b' && S[i + 1] == 'a'))
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

// another
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    bool ok = false;
    for (int i = 0; i + 1 < N; i++)
    {
        if ((S[i] == 'a' && S[i + 1] == 'b') ||
            (S[i] == 'b' && S[i + 1] == 'a'))
        {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}
