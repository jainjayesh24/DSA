#include<iostream>

using namespace std;

int main(){
    int n,m;

    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u >> v;
        adj[u][v] = 1; // Assuming directed graph, for undirected use adj[v][u] = 1 as well
        adj[v][u] = 1; // Uncomment this line for undirected graph
    }

    return 0;
}