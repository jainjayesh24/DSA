// User Function Template
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<int> result(V,INT_MAX);
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        
        vector<pair<int,int>> adjL[V];
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adjL[u].push_back({v,w});
            adjL[v].push_back({u,w});
            
        }
        
        result[src] = 0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            
            pq.pop();
            
            for(auto nbr:adjL[node]){
                int currnode = nbr.first;
                int distance = nbr.second;
                
                if(distance + d < result[currnode]){
                    result[currnode] = distance + d;
                    pq.push({distance+d,currnode});
                }
            }
        }
        
        return result;
        
    }
};

