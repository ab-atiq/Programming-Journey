/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.codechef.com/problems/OCTATHON
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x_hours;
    scanf("%d", &x_hours);
    if (x_hours < 3)
    {
        cout << "GOLD\n";
    }
    else if (x_hours >= 3 && x_hours < 6) // else if(x_hours < 6)
    {
        cout << "SILVER\n";
    }
    else
    {
        cout << "BRONZE\n";
    }
    return 0;
}