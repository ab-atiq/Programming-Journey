#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, c;
    cin >> a >> b >> c;
    cout<<max(a, max(b,c))<<endl;
    cout<<max({a,b,c})<<endl;

    return 0;
}