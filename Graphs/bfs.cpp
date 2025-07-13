#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> result;
        vector<int> visited(n);
        queue<int> q;
        
        q.push(0);
        
        visited[0] = 1;
        
        while(q.size()!=0){
            int front = q.front();
            q.pop();
            result.push_back(front);
            
            for(int nbr:adj[front]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
            
        }
        return result;
    }
};