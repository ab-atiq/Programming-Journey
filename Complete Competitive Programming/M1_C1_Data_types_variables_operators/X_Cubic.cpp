/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_B
#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    scanf("%d", &x);
    // int cube = x * x * x;
    int cube = (int)pow(x, 3);
    printf("%d\n", cube);
    return 0;
}