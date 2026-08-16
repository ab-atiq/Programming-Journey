#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b || b == c || c == a)
        {
            cout << 0 << endl;
        }
        else
        {
            int cnt = 0;
            while (true)
            {
                if (a == b || b == c || c == a)
                {
                    break;
                }
                else
                {
                    // int minv = min({a, b, c});
                    // int maxv = max({a, b, c});
                    // if(minv==a){
                    //     a+=1;
                    // }else if(minv==b){
                    //     b+=1;
                    // }else{
                    //     c+=1;
                    // }
                    // if(maxv==a)
                    if (a > b && a > c)
                    {
                        // a is maximum
                        if (b < c)
                        {
                            a--;
                            b++;
                        }
                        else
                        {
                            a--;
                            c++;
                        }
                    }
                    else if (b > a && b > c)
                    {
                        // b is maximum
                        if (a < c)
                        {
                            b--;
                            a++;
                        }
                        else
                        {
                            b--;
                            c++;
                        }
                    }
                    else
                    {
                        // c is maximum
                        if (a < b)
                        {
                            c--;
                            a++;
                        }
                        else
                        {
                            c--;
                            b++;
                        }
                    }
                }
                cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}