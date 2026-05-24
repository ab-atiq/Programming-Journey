/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/DIWALIDISC

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << a - b << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}