/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_2_A

// accepted code - TC O(q) and SC O(n * q) in worst case when all q operations are push and all of them are on different stacks
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    map<int, stack<int>> mp_st;
    for (int i = 0; i < q; i++)
    {
        int op, t, x;
        cin >> op;
        if (op == 0)
        {
            // push x to stack t
            cin >> t >> x;
            mp_st[t].push(x);
        }
        else if (op == 1)
        {

            // top element
            cin >> t;
            if (!mp_st[t].empty())
            {
                cout << mp_st[t].top() << "\n";
            }
        }
        else if (op == 2)
        {
            // pop element
            cin >> t;
            if (!mp_st[t].empty())
            {
                mp_st[t].pop();
            }
        }
    }
    return 0;
}