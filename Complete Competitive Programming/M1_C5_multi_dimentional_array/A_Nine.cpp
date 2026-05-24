/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc309/tasks/abc309_a

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    if (A >= 1 && B <= 3)
    {
        cout << "Yes" << endl;
    }
    else if (A >= 4 && B <= 6)
    {
        cout << "Yes" << endl;
    }
    else if (A >= 7 && B <= 9)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int A, B;
    scanf("%d%d", &A, &B);

    if (A == 1 && B == 2)
        printf("Yes\n");
    else if (A == 2 && B == 3)
        printf("Yes\n");
    else if (A == 4 && B == 5)
        printf("Yes\n");
    else if (A == 5 && B == 6)
        printf("Yes\n");
    else if (A == 7 && B == 8)
        printf("Yes\n");
    else if (A == 8 && B == 9)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}