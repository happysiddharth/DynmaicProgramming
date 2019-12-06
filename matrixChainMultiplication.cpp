#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

int matrixChainMultiplication(int m[],int i, int j){
    if(i==j){
        return 0;
    }

    if(arr[i][j]!=-1){
        return arr[i][j];
    }

    int ans = INT_MAX;

    for(int k=i;k<j;k++){
        int temp = matrixChainMultiplication(m,i,k)+matrixChainMultiplication(m,k+1,j)+m[i-1]*m[k]*m[j];
        ans = min(ans , temp);
    }

    arr[i][j] = ans;
    return ans;


}

int main()
{
   int matrix[]={1,2,3,4};
   int n = sizeof(matrix)/sizeof(int);
   memset(arr,-1,sizeof arr);
   cout<<"matrix "<<matrixChainMultiplication(matrix,1,n-1);

    return 0;
}
