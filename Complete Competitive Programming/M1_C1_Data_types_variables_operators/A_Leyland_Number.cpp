/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://atcoder.jp/contests/abc320/tasks/abc320_a?lang=en
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    // int a_b = pow(a, b); // a^b
    // int b_a = pow(b, a); // b^a
    int a_b = 1, b_a = 1;
    for (int i = 1; i <= b; i++) // b times multiply with a
        a_b *= a;
    for (int i = 1; i <= a; i++) // a times multiply with b
        b_a *= b;
    printf("%d\n", a_b + b_a);
    return 0;
}