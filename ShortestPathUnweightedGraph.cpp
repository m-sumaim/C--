// Question  based on BFS


#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, -1);
        queue<int> q;
        vector<bool> vis(N, false);
        vis[src] = true;
        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &i:adj[u]){
                if(vis[i]==false){
                    dist[i] = dist[u]+1;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        return dist;
    }
};

int main(){
  int N=9, M=10;
  vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

  Solution obj;
  vector<int> ans = obj.shortestPath(edges, N, M, 0);
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  return 0;



}