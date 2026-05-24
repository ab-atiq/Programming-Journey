/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_4_B

#include <stdio.h>
int main()
{
    // int r; // not real
    double r; // real
    scanf("%lf", &r);
    double pi = 3.14159265358979323846;
    double area = pi * r * r;
    double circumference = 2 * pi * r;
    printf("%.6f ", area);
    printf("%.6f\n", circumference);
    return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
    double pi = acos(-1); // acos means arccosine or cosine inverse
    double r;
    scanf("%lf", &r);

    double area = pi * r * r;
    double circ = 2 * pi * r;
    printf("%.6lf %.6lf\n", area, circ);
    return 0;
}