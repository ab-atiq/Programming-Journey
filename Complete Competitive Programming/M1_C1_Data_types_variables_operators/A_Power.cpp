/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://atcoder.jp/contests/abc283/tasks/abc283_a?lang=en
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    // a^b = a*a*a*...*a (b times)
    int mul = 1;
    for (int i = 0; i < b; i++)
    {
        mul *= a;
    }
    cout << mul << endl;
    return 0;
}

// pow function
#include <stdio.h>
#include <math.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int result = pow(A, B);
    printf("%d\n", result);

    return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (int)pow(a, b)); // pow return long long int value. So, we need to type cast it to int.
    return 0;
}