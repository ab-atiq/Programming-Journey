/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/practice/course/cpp/PCPP11/problems/CPPDEBUG11

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x;
        cin >> x;
        if (x > 30)
        {
            cout << "YES\n"; // subscription needed
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}