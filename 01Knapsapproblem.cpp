#include<iostream>

using namespace std;

void knapsapProblem(int w[],int cost[],int totalWeight,int n){

	int ans[n+1][totalWeight+1];
	for(int i=0;i<=n;i++){
		ans[i][0]=0;
	}
	for(int i=0;i<=totalWeight;i++){
		ans[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=totalWeight;j++){
			if(w[i-1]<=j){
				ans[i][j]=max(ans[i-1][j],cost[i-1]+ans[i-1][j-w[i-1]]);
			}else{
				ans[i][j] = ans[i-1][j];
			}
		}
	}



		cout<<ans[n][totalWeight];

}
int main(){
	int w[]={1 ,2 ,3 ,2 ,2 };
	int cost[]={8, 4 ,0, 5, 3};
	int weight = 4;
	knapsapProblem(w,cost,weight,6);
	return 0;
}
