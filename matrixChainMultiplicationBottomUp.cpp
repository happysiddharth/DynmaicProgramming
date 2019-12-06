#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

int matrixChainMultiplicationBottomUp(int m[],int n)
{
    for(int i=0;i<n;i++){
        arr[i][i]=0;
    }


    for(int l=2;l<n;l++){

        for(int i=1;i<=n-l;i++){
            int j = i+l-1;
            arr[i][j] = INT_MAX;
            for(int k = i;k<=j;k++){
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k+1][j]+m[i-1]*m[k]*m[j]);
            }
        }
    }
    return arr[1][n-1];
}
int main()
{
   int matrix[]={1,2,3,4};
   int n = sizeof(matrix)/sizeof(int);
   memset(arr,-1,sizeof arr);
   cout<<"matrix "<<matrixChainMultiplicationBottomUp(matrix,4);

    return 0;
}
