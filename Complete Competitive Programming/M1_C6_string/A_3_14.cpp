/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc314/tasks/abc314_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    cout << pi.substr(0, 2 + N) << endl;
    // "3." is 2 characters → total length = 2 + N

    return 0;
}
