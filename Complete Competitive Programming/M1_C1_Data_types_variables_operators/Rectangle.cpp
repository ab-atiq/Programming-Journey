/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://www.geeksforgeeks.org/maths/area-perimeter-formulas/
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_C
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int area = a * b;
    int perimeter = 2 * (a + b);
    printf("%d %d\n", area, perimeter);
    return 0;
}