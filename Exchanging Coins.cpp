#include<iostream>
#include<climits>
#include<vector>
using namespace std;
long long dp[10000000];
long long f(long long  n){
    if(n<=4){
        return n;
    }
    long long ans= INT_MIN;
    for(long long i=5;i<=n;i++){

        dp[i] =  max(i,dp[i/2]+dp[i/3]+dp[i/4]);
    }
    //recursive approach
    //long x = n;
   // long y = f(n/2) + f(n/3) + f(n/4);
   // return max (x,y);
   return dp[n];
}
long long recur(long long n){
    if(n<=0){
        return 0;

    }
    long x = n;
    long y = f(n/2) + f(n/3) + f(n/4);
    return max (x,y);
}




long long f1(long long n){
    if(n == 0) return 0;

    if(n <= 100000){
        return dp[n];
    }

    long long  q1 = max(n/2, f(n/2));
    long long  q2 = max(n/3, f(n/3));
    long long  q3 = max(n/4, f(n/4));

    return max(n, q1+q2+q3);
}

long long splitN(long long n)
{
	long long n1=n/2, n2=n/3, n3=n/4;
	if(n1 + n2 + n3 > n)
	{
		n1 = splitN(n1);
		n2 = splitN(n2);
		n3 = splitN(n3);
		n = n1+n2+n3;
	}
	return n;
}

int main() {
    long n;
    cin>>n;
    dp[0]=0;
    dp[1] =1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    cout<<recur(n);

	return 0;
}
