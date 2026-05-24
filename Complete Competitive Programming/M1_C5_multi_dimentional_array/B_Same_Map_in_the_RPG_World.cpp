/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc300/tasks/abc300_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}

// cps
#include<stdio.h>

int main(){

    int h, w;
    scanf("%d%d",&h,&w);

    char A[h][w], B[h][w], temp;

    scanf("%c",&temp);

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%c",&A[i][j]);
        }
        scanf("%c",&temp);
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%c",&B[i][j]);
        }
        scanf("%c",&temp);
    }

    int flag=0;
    for(int s=0; s<h; s++){
        for(int t=0; t<w; t++){
            int flag2=1;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    int currentvalue=A[(i+s)%h][(j+t)%w];
                    if(currentvalue!=B[i][j]){
                        flag2=0;
                    }
                }
            }
            if(flag2==1){
                flag=1;
            }
        }
    }

    if(flag==1) printf("Yes\n");
    else printf("No\n");

    return 0;
}

// chatgpt
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++)
        cin >> A[i];
    for (int i = 0; i < H; i++)
        cin >> B[i];

    for (int s = 0; s < H; s++)
    {
        for (int t = 0; t < W; t++)
        {
            bool match = true;
            for (int i = 0; i < H && match; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (B[i][j] != A[(i + s) % H][(j + t) % W])
                    {
                        match = false;
                        break;
                    }
                }
            }
            if (match)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
