void dfs(int node, vector<vector<int>> &edges, vector<int> &vis,
         vector<int> &temp) {
  vis[node] = 1;
  temp.push_back(node);
  for (int it : edges[node]) {
    if (!vis[it]) {
      dfs(it, edges, vis, temp);
    }
  }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  for (auto e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  vector<vector<int>> ans;
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      vector<int> temp;
      dfs(i, adj, vis, temp);
      ans.push_back(temp);
    }
  }
  return ans;
}