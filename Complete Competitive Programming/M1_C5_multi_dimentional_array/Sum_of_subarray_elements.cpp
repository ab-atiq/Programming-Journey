/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://eolymp.com/en/problems/9562
// my solution + cps
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows, cols;
    cin >> rows >> cols;
    int matrix[rows + 1][cols + 1];
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int sum = 0;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            sum += matrix[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}