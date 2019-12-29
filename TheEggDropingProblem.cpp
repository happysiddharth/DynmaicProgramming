#include<iostream>
#include<climits>
using namespace std;

int main(){
    int floors, eggs;
    cin>>floors>>eggs;
    int dp[eggs+1][floors+1];
    for(int i=0;i<=floors;i++)dp[0][i]=0;
    for(int j=0;j<=eggs;j++)dp[j][0]=0;
    for(int i=1;i<=floors;i++)dp[1][i]=i;
    for(int j=1;j<=eggs;j++)dp[j][1]=1;


    for(int i=2;i<=eggs;i++){
        for(int j=2;j<=floors;j++){
            int ans = INT_MAX;

            for(int k=1;k<=j;k++){


                ans = min(ans,1+max(dp[i-1][k-1],dp[i][j-k]));
            }
            dp[i][j] = ans ;
        }
    }
    cout<<dp[eggs][floors];
}
