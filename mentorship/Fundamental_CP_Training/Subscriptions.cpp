// https://www.codechef.com/practice/course/logical-problems/DIFF800/problems/SUBSCRIBE_

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, X;
        cin >> N >> X;
        // int ceil_N = (N + 5) / 6;
        int ceil_N = ceil((float)N / 6);
        cout << ceil_N * X << endl;
    }
    return 0;
}