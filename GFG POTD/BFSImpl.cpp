#include<bits/stdc++.h>
using namespace std;

// Create Adjacency List
void adjList(unordered_map<int, set<int>> &adj, vector<pair<int, int>> edges){
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

// BFS traversal 
void bfs(unordered_map<int, set<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;

    adjList(adj, edges);

    for(int i = 0; i<vertex; i++){
        if(!visited[i])
            bfs(adj, ans, visited, i);
    }



    return ans;
}
