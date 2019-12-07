#include<iostream>
using namespace std;
#define v 5


void printSolution(int path[])  
{  
    cout << "Solution Exists \n"   ;  
    for (int i = 0; i < v; i++)  
        cout << path[i] << " ";   
   
    cout << path[0] << " ";  
    cout << endl; 
}  
  
  
bool isSafe(bool graph[v][v],int *path,int vertex,int position){
	if(graph[path[position-1]][vertex]==0){
		return false;
	}
	for(int i=0;i<position;i++ ){
		if(path[i]==vertex){
			return false;
		}
	}
	return true;
}

bool hamiltonianCycleUtility(bool graph[v][v],int *path,int position){
	if(position==v){
		if(graph[path[position-1]][path[0]]==0){
			return false;
		}
		printSolution(path);			
		}
	
	for(int i=1;i<v;i++){
		if(isSafe(graph,path,i,position)){
			path[position]=i;
			int next = hamiltonianCycleUtility(graph,path,position+1);
			if(!next){
				return false;
			}
			path[position] = -1;
		}
	}
	return true;
}

int main(){
	bool graph1[v][v] = {{0, 1, 1, 1, 0},  
                        {1, 1, 1, 0, 1},  
                        {1, 1, 0, 1, 0},  
                        {1, 0, 1, 0, 1},  
                        {1, 0, 0, 1,0}};  
    int *path = new int[v];  
    for (int i = 0; i < v; i++)  
        path[i] = -1;  
   path[0] = 0;  
  
   
    hamiltonianCycleUtility(graph1, path,1) ;
     
  
    
   
   
                        
}
