// https://www.codechef.com/problems/TELHOME

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D, T;
    cin >> D >> T;
    if (D < T)
        cout << 0 << endl;
    else
        cout << D - T << endl;
    return 0;
}