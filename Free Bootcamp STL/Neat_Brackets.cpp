/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://toph.co/p/neat-brackets

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // char parenthesis[26];
    string parenthesis;
    cin >> parenthesis;
    stack<char> st;
    for (char c : parenthesis)
    {
        if (st.empty() || c == '(')
        {
            st.push(c);
        }
        else if (c == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            cout << "No\n";
            return 0;
        }
    }
    if (st.empty())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}