#include <bits/stdc++.h>

bool bfs(int src,vector<vector<int>> &adj,vector<int> &vis) {
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push({it, node});
      } else if (parent != it) {
        return true;
      }
    }
  }
  return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) { 
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }
  vector<int> vis(n+1,0);
  for(int i = 1; i <= n;i++) {
      if(!vis[i]) {
          if(bfs(i,adj,vis)) {
              return "Yes";
          }
      }
  }
  return "No";
}
