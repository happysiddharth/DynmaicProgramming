longestCommonSubsequence
#include <iostream>
#include <string.h>
using namespace std;

char ans[100][100];

int longestCommonSubsequence(string x , string y ){
   int m = x.length();
   int n = y.length();
   int dp[m+2][n+2];

   for(int i=0;i<=m;i++){
       dp[i][0]=0;
   }
    for(int i=0;i<=n;i++){
       dp[0][i]=0;
   }

   for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
           int q = 0;
           if(x[i-1]==y[j-1]){
               q = 1+dp[i-1][j-1];
           }else{
              q = max(dp[i-1][j],dp[i][j-1]);
           }
           dp[i][j]=q;
       }
   }
   return dp[m][n];

}

int main()
{
   cout<<longestCommonSubsequence("siddharth","sidd");

    return 0;
}

