#include<bits/stdc++.h>
using namespace std;
int a[5000],b[5000],dp[5000][5000];
int boys,girls;

int f(int i,int j){
    if(i==boys){
        return 0;
    }
    if(j==girls){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int x = abs(a[i]-b[j]) + f(i+1,j+1);
    int y = f(i,j+1);
    return dp[i][j] = min(x,y);
}

int main()
{

    memset(dp,-1,sizeof(dp));
    cin>>boys>>girls;
    for(int i=0;i<boys;i++){
        cin>>a[i];
    }
    for(int i=0;i<girls;i++){
        cin>>b[i];
    }
    sort(a,a+boys);
    sort(b,b+girls);

    cout<<f(0,0)<<endl;

}
