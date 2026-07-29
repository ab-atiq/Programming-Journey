// https://www.codechef.com/problems/CONVEYOR
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, P;
        cin >> N >> P;

        string S;
        cin >> S;

        int leftChange = 0;
        int rightChange = 0;

        // Make object leave from the left
        for (int i = P - 1; i >= 0; i--)
        {
            if (S[i] == 'R')
                leftChange++;
        }

        // Make object leave from the right
        for (int i = P - 1; i < N; i++)
        {
            if (S[i] == 'L')
                rightChange++;
        }

        cout << min(leftChange, rightChange) << endl;
    }

    return 0;
}

// problem link: https://www.codechef.com/problems/CONVEYOR

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tc;
    cin>>tc;
    while(tc--){
        int n, p;
        cin>>n>>p;
        string st;
        cin>>st;
        
        // cost 1 - left direction
        int cost_1 = 0;
        for(int i=0;i<p;i++){
            if(st[i]!='L'){
                cost_1++;
            }
        }
        // cost 2 - right direction
        int cost_2 = 0;
        for(int i=p-1;i<n;i++){
            if(st[i]!='R'){
                cost_2++;
            }
        }
        cout<<min(cost_1, cost_2)<<endl;
    }
}
