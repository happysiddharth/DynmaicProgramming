#include<iostream>
using namespace std;
int lis(int *arr,int n){
    int dp[n];
    int ans = -1;
    for(int i=0;i<n;i++)dp[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                int cost = 1+dp[j];
                dp[i] = max(cost,dp[i]);
            }
            ans=max(ans,dp[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Longest increasing subsequence is\t"<<lis(arr,n);
}
