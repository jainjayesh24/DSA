// toposort
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> toposort(int V,vector<int> adj[]){
        vector<int> ans;
        vector<int> inDegree(V);
        for(int i = 0;i<V;i++){
            for(int it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0;i<V;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto it: adj[front]){
                inDegree[it]--;
                
                if(inDegree[it] == 0) q.push(it);
            }
            
        }
         return ans;    
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> topo = toposort(V,adj);
        
        if(topo.size() == V) return false;
        return true;
    }
};