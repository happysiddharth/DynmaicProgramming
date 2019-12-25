#include<iostream>
#include<climits>
using namespace std;
    int n=4;
    int graph[10][10]={{0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {25,34,10,0}
    };
    int dp[1000][1000];
    int mask = (1<<4)-1;

int travellingSellsman(int vertex,int visited){
   if(visited==mask){
        return graph[vertex][0];
   }
   if(dp[visited][vertex]!=-1){
    return dp[visited][vertex];
   }
   int answ = INT_MAX;
   for(int i=0;i<n;i++){
        if((visited&(1<<i))==0){
            int ans = graph[vertex][i] + travellingSellsman(i,visited|(1<<i));
            answ = min(answ,ans);
        }

   }
   return dp[visited][vertex] = answ;
}
int main()
{
    for(int i = 0;i<16;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<travellingSellsman(0,1);


}
