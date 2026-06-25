// problem link: https://www.hackerrank.com/contests/phitron-code-fest-2-b9/challenges/celebrity-on-stage/problem?isFullScreen=false

#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int my_h = h[k - 1];
    int cnt_pre = 0;
    for (int i = 0; i < k - 1; i++)
    {
        if (h[i] > my_h)
        {
            cnt_pre++;
        }
    }
    int cnt_post = 0;
    for (int i = k; i < n; i++)
    {
        if (h[i] < my_h)
        {
            cnt_post++;
        }
    }
    cout << cnt_pre << " " << cnt_post << endl;
    return 0;
}