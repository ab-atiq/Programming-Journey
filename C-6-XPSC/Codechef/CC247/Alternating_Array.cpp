// link: https://www.codechef.com/START247C/problems/ALTARR
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];

        int change1 = 0; // Odd Even Odd Even...
        int change2 = 0; // Even Odd Even Odd...

        for (int i = 0; i < N; i++)
        {
            // Pattern-1
            if (i % 2 == 0)
            {
                // even index must contain odd value
                // if not odd value then we must change
                if (A[i] % 2 == 0)
                    change1++;
            }
            else
            {
                // odd index must contain even value
                // if not even value then we must change
                if (A[i] % 2 != 0)
                    change1++;
            }

            // Pattern-2
            if (i % 2 == 0)
            {
                // even index must contain even value
                // if not even value then we must change
                if (A[i] % 2 != 0)
                    change2++;
            }
            else
            {
                // odd index must contain odd value
                // if not odd value then we must change
                if (A[i] % 2 == 0)
                    change2++;
            }
        }

        cout << min(change1, change2) << endl;
    }

    return 0;
}

// problem link: https://www.codechef.com/problems/ALTARR
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int sz;
        cin>>sz;
        int arr[sz+1];
        for(int i=1;i<=sz;i++){
            cin>>arr[i];
        }
                       // 1 2 3 4 5
        int cost1 = 0; // E O E O E 
        int cost2 = 0; // O E O E O 
        for(int i=1;i<=sz;i++){
            if(i%2 == 1){ // index odd
                if(arr[i]%2!=0){ // value not even then cost increate
                    cost1++;
                }
            }else{
                // even index
                if(arr[i]%2==0){
                    cost1++;
                }
            }
            
            // O E O E O 
            if(i%2 == 1){ // index odd
                if(arr[i]%2==0){ // value even then cost increate
                    cost2++;
                }
            }else{
                // even index
                if(arr[i]%2!=0){ // value odd then cost increate
                    cost2++;
                }
            }
        }
        cout<<min(cost1, cost2)<<endl;
    }
}
