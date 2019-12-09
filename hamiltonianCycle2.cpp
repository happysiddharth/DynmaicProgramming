#include<iostream>
using namespace std;
#define v 5


void printSolution(int color[])  
{  
    cout << "Solution Exists \n"   ;  
    for (int i = 0; i < v; i++)  
        cout << color[i] << " ";   
   
    cout << color[0] << " ";  
    cout << endl; 
}  
  
  
bool isSafe(bool graph[v][v],int *color,int vertex,int c){

	for(int i=0;i<v;i++ ){
		if(graph[vertex][i]!=0 and color[i]==c){
			return false;
		}
	}
	return true;
}

bool hamiltonianCycleUtility(bool graph[v][v],int *path,int vertex,int c){
	if(vertex==v){
		printSolution(path);			
		}
	
	for(int i=0;i<v;i++){
		if(isSafe(graph,path,i,c)){
			path[vertex]=i;
			int next = hamiltonianCycleUtility(graph,path,i+1,i+1);
			if(!next){
				return false;
			}
			path[vertex] = -1;
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
  // path[0] = 0;  
  
   
    hamiltonianCycleUtility(graph1, path,0,0) ;
     
  
    
   
   
                        
}
