/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/SINGLEUSE

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int h, x, y;
        cin >> h >> x >> y;
        int cnt = 0;

        // Use the special attack once if it can be used
        if (h >= y)
        {
            h -= y;
            cnt++;
        }

        // Use the normal attack until the monster is defeated
        while (h > 0)
        {
            h -= x;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int H, X, Y;
        cin >> H >> X >> Y;
        // Option 1: just normal attack
        // int normalAttacks = (H + X - 1) / X;
        int normalAttacks = ceil(H / X);
        // Option 2: first special attack, then normal attack
        int remainingHealth = H - Y;
        // int normalAfterSpecial = (remainingHealth + X - 1) / X;
        int normalAfterSpecial = ceil(remainingHealth / X);
        int usingSpecial = 1 + normalAfterSpecial;
        cout << min(normalAttacks, usingSpecial) << '\n';
    }
    return 0;
}