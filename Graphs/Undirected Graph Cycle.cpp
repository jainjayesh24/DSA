
//Parent check and bfs
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool bfs(int node,vector<int> adj[],vector<int> &visited){
        visited[node] = 1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            int front = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(int nbr:adj[front]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push({nbr,front});
                }
                else if(nbr != parent) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)) return true;
            }
        }
        
        return false;
    }
};