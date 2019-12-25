#include<iostream>
using namespace std;

int ceil_index(int arr[],int l,int r,int key){
    while(r-l>1){
        int m = (r+l)/2;
        if(arr[m]>=key){
            r=m;
        }else{
            l=m;
        }
    }
    return r;
}

int lcs_nlogn(int arr[],int n){
    int temp[n]={0};
    temp[0]=arr[0];
    int len = 1;
    for(int i=1;i<n;i++){
        if(temp[0]>arr[i]){
            temp[0]=arr[i];
        }else if(arr[i]>temp[len-1]){
            temp[len++] = arr[i];
        }else{
            temp[ceil_index(temp,0,len-1,arr[i])] = arr[i];
        }
    }
    return len;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lcs_nlogn(arr,n);
}
