/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/COLORB

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, b;
    cin >> r >> b;
    int make_green = 0; // common from r & b
    if (r >= b)
    {
        make_green = r - (r - b);
        // r -= r - (r - b);
        r -= make_green;
        // b = 0;
        b -= make_green;
    }
    else if (b > r)
    {
        make_green = b - (b - r);
        b -= make_green;
        r -= make_green;
    }

    int max_skill = make_green * 5 + b * 2 + r * 1;
    cout << max_skill << endl;
    return 0;
}