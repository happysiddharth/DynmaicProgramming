 #include<bits/stdc++.h>

 using namespace std;
 string s1;
 string s2;
 string s3;
bool f(int i,int j,int k){
    if((s1.length()+s2.length())!= s3.length()){
        return false;
    }
    if(s1.length() == i){
        return s2[j] == s3[k];
    }
    if(s2.length() == j){
        return s1[i] == s3[k];
    }
    if(s1[i]==s3[k]and f(i+1,j,k+1) || s2[j]==s3[k] and f(i,j+1,k+1)){
        return true;
    }else{
        return false;
    }
}

int main()
{

    cin>>s1>>s2>>s3;
    cout<<f(0,0,0);

}
