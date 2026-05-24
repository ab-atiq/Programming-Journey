#include <bits/stdc++.h>
using namespace std;
int main()
{
    // long long int a, b, c;
    // cin >> a >> b >> c;
    // cout<<max(a, max(b,c))<<endl;
    // cout<<max({a,b,c})<<endl;

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}