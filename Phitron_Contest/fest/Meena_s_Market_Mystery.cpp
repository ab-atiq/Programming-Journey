
#include <iostream>

using namespace std;

int main()
{
    int st = 0, cnt = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (st + y - i <= x)
        {
            st += y;
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
