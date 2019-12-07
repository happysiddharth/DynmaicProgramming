#include<iostream>
using namespace std;
int main(){
	int V=5;
	  bool available[V]; 
    for (int cr = 0; cr < V; cr++) 
        available[cr] = false; 
    int cr;
	 for (cr = 0; cr < V; cr++) 
            if (available[cr] == false) 
                break;
                
    cout<<cr;
}
