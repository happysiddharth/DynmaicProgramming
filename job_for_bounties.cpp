#include<iostream>
#include<stack>
using namespace std;
int main() {
    string s;
    stack<int> stk;
    cin>>s;
    int res =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            stk.push(i);
        }else{
            stk.pop();
            if(!stk.empty()){
                res = max(res,i-stk.top());
            }else{
                stk.push(i);
            }
        }
    }

    cout<<res;

	return 0;
}
