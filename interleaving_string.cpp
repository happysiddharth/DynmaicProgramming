 #include<bits/stdc++.h>

 using namespace std;
 string s1;
 string s2;
 string s3;
 bool dp[10000][10000]={-1};
bool f(int i,int j,int k){
    if((s1.length()+s2.length())!= s3.length()){
        return false;
    }
    if(s1.length()==i and s2.length()==j){
        return true;
    }
    if(dp[i][j]=!-1){
        return dp[i][j]?true:false;
    }
    if(s1.length() == i){
        return   dp[i][j] = s2[j] == s3[k] and f(i,j+1,k+1);
    }
    if(s2.length() == j){
        return dp[i][j] = s1[i] == s3[k] and f(i+1,j,k+1);
    }
    if(s1[i]==s3[k]and f(i+1,j,k+1) || s2[j]==s3[k] and f(i,j+1,k+1)){
        return  dp[i][j] = true;
    }else{
        return dp[i][j] = false;
    }
}
int main()
{
    cin>>s1>>s2>>s3;
    if(f(0,0,0)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

}
