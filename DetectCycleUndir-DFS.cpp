#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
   Graph(int V);
   void addEdge(int v, int w);
   bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); i++){
        if(!visited[*i]){
            if(isCyclicUtil(*i, visited, v))
                return true;
        }
        else if(*i != parent)
           return true;
    }
    return false;


}

bool Graph::isCyclic()
{
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
       visited[i] = false;
    
    for(int j = 0; j<V; j++){
        if(!visited[j]){
            if(isCyclicUtil(j, visited, -1))             // every starting vertext will have no parent : so -1 as it's parent
               return true;
        }
    }
    return false;
}


int main(){
    Graph g1(5);
    g1.addEdge(1,0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
 
 return 0;
}