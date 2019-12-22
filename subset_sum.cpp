#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],dp[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0] = max(0,arr[0]);
    dp[1] = max(0,arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]);
        dp[i] = max(dp[i],dp[i-2]+arr[i]);
    }
    cout<<dp[n-1];
}
