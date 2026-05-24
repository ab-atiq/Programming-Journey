/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/practice/course/basic-programming-concepts/DIFF500/problems/PRACTICEPERF

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w1, w2, w3, w4;
    cin >> w1 >> w2 >> w3 >> w4;
    if (w1 >= 10 && w2 >= 10 && w3 >= 10 && w4 >= 10)
    {
        cout << 4 << endl;
    }
    else if ((w1 >= 10 && w2 >= 10 && w3 >= 10) || (w1 >= 10 && w2 >= 10 && w4 >= 10) || (w4 >= 10 && w2 >= 10 && w3 >= 10) || (w1 >= 10 && w4 >= 10 && w3 >= 10))
    {
        cout << 3 << endl;
    }
    else if ((w1 >= 10 && w2 >= 10) || (w1 >= 10 && w3 >= 10) || (w1 >= 10 && w4 >= 10) || (w2 >= 10 && w3 >= 10) || (w2 >= 10 && w4 >= 10) || (w3 >= 10 && w4 >= 10))
    {
        cout << 2 << endl;
    }
    else if (w1 >= 10 || w2 >= 10 || w3 >= 10 || w4 >= 10)
    {

        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}