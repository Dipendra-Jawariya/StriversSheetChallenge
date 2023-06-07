bool dfs_check(int node, vector<int> &vis, vector<int> &pathVis,
               vector<vector<int>> &adj) {
  vis[node] = 1;
  pathVis[node] = 1;

  for (auto it : adj[node]) {
    if (!vis[it]) {
      if (dfs_check(it, vis, pathVis, adj))
        return true;
    } else if (pathVis[it])
      return true;
  }
  pathVis[node] = 0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  vector<vector<int>> adj(n + 1);
  int m = edges.size();
  for (int i = 0; i < m; i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
  }
  vector<int> vis(n + 1, 0);
  vector<int> pathVis(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs_check(i, vis, pathVis, adj))
        return 1;
    }
  }
  return 0;
}