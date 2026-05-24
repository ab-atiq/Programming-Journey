/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/TOYS

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int res = n - m;
    if (res < 0)
        res = 0;
    cout << res << endl;
    return 0;
}