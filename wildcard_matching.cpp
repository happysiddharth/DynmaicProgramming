#include <cstring>
#include <iostream>

using namespace std;

int main() {
    string text, pattern;
    cin>>text>>pattern;
    int textL = text.length();
    int patternL = pattern.length();

    bool dp[patternL+1][textL+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = 1;

      for (int j = 1; j <= patternL; j++)
        if (pattern[j - 1] == '*')
            dp[j][0] = dp[j-1][0];

    for(int i=1;i<=patternL;i++){
        for(int j=1;j<=textL;j++){
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(pattern[i-1]=='*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }else{
                dp[i][j] = false;
            }
        }
    }

    if(dp[patternL][textL]){
        cout<<"MATCHED"<<endl;
    }else{
       cout<<"NOT MATCHED";
    }

	return 0;
}
