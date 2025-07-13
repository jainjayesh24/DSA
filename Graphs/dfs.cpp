#include <bits/stdc++.h>
using namespace std;
void DFS(int node,vector<int> adj[],vector<int> &visited,vector<int> &dfs){
        dfs.push_back(node);
        visited[node] = 1;
        for(int nbr:adj[node]){
            if(!visited[nbr]){
                DFS(nbr,adj,visited,dfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> visited(V,0);

        DFS(0,adj,visited,dfs);

        return dfs;
    }