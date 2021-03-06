#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> edge;
    int m ;
public:
    void addEdge(T u,T v,bool isBirectional=true){
        edge[u].push_back(v);
        if(isBirectional){
            edge[v].push_back(u);
        }
    }
   bool chooseColor(T node,T v, map<T,int> &color){
       do{
            int flag=0;
            color[v] = (color[v]+1)%(m+1);
            if(color[v]==0){
                    m++;
                //return false;
            }
            for(auto neighbour:edge[v]){
                if(color[neighbour]==color[v]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return true;
            }



        }while(true);


   }
   void color(T src){

       map<T,int> color;
        queue<T> que;
		map<T,bool> visited;
		que.push(src);
		 visited[src] = 1;
       color[src] = 1;
       int flag = 1;


       while(!que.empty()){
        T node = que.front();
        que.pop();
        for(auto neighbour:edge[node]){
            if(visited[neighbour]==0){
                visited[neighbour]=1;
                que.push(neighbour);
                if(chooseColor(node,neighbour,color)==false){
                    cout<<"colors are to less increase the no of colors\n";
                    flag=0;
                }
            }
        }

       }

       if(flag==1){
            cout<<m<<endl;
        for(auto a:color){
        cout<<a.first<<"->"<<a.second<<endl;
       }
       }




   }
	void printGraph(){
	    cout<<"\n";
			for(auto i:edge){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<"->";
				}
				cout<<"\n";
			}
		}


};
int main(){
	Graph<string> g;

       g.addEdge("english","programming logic");
    g.addEdge("maths", "programming logic");
    g.addEdge("programming logic","html");
    g.addEdge("programming logic","python");
    g.addEdge("programming logic","java");
    g.addEdge("programming logic","js");
    g.addEdge("python","wd");
    g.addEdge("html","css");
    g.addEdge("css","js");
    g.addEdge("js","wd");
    g.addEdge("java","wd");
    g.addEdge("python","wd");







	g.color("english");
	g.printGraph();
	return 0;
}
