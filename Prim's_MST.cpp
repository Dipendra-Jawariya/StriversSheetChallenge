#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, 
vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto edge : g) {
        adj[edge.first.first].push_back(make_pair(edge.first.second,edge.second));
        adj[edge.first.second].push_back(make_pair(edge.first.first,edge.second));
    }
   priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, 
   greater<pair<pair<int, int>, int>>> pq;
    vector<int> vis(n+1,0);
    vector<pair<pair<int,int>,int>> mst;
    pq.push({{0,1},-1});
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first.first;
        int node = it.first.second;
        int parent = it.second;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        if(parent != -1) {
            mst.push_back({{parent,node},wt});
        }
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgWt = it.second;

            if(!vis[adjNode]) {
                pq.push({{edgWt,adjNode},node});
            }
        }
    }
    return mst;
}
