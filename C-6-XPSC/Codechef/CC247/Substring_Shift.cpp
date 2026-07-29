// problem link: https://www.codechef.com/problems/STRINGSHIFT

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        // first z find 
        int ind=-1;
        // int sz = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='z'){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            cout<<s<<endl;
        }else{
            // continious z change
            while(ind<n){
                if(s[ind]=='z'){
                    s[ind] = 'a';
                    ind++;
                }else{
                    break;
                }
                
            }
            cout<<s<<endl;
        }
        
    }
}
