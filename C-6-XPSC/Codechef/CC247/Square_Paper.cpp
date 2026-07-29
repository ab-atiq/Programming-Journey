// https://www.codechef.com/problems/SQPAPER

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int min_val = min(a, b);
    int rec_val = min_val * min_val;
    cout << rec_val << endl;

    return 0;
}


// problem link: https://www.codechef.com/problems/SQPAPER

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int a,b;
    cin>>a>>b;
    int min_val;
    if(a<b){
        min_val=a;
    }else{
        min_val=b;
    }
    cout<<min_val*min_val<<endl;
    return 0;
}
