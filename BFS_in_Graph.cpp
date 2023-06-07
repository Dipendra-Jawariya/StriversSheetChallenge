#include <bits/stdc++.h>

void bfsTrav(int start, int V, vector<vector<int>> &adj, vector<int> &vis,
             vector<int> &ans) {
  vis[0] = 1;
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();

    q.pop();
    ans.push_back(node);
    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  // return bfs;
}
vector<int> BFS(int V, vector<pair<int, int>> edges) {
  vector<vector<int>> adj(V);
  for (auto e : edges) {
    adj[e.first].push_back(e.second);
    adj[e.second].push_back(e.first);
  }
  for (int i = 0; i < V; i++) {
    sort(adj[i].begin(), adj[i].end());
  }
  vector<int> bfs;
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      bfsTrav(i, V, adj, vis, bfs);
    }
  }
  return bfs;
}