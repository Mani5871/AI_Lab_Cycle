#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}


void dfs(vector<pair<int, int>> adj[], int v, int n)
{
    static vector<bool>visit(n, false);
   
    visit[v] = true;
    cout<<v<<" ";
   
    for(auto i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visit[i -> first])
            dfs(adj, i -> first, n);
}


int main() {
    vector<pair<int, int>> adj[10];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    
    dfs(adj, 0, 4);
}
