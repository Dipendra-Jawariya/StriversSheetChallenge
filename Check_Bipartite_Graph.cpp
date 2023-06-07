
bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &adj) {
  color[node] = col;
  for (auto it : adj[node]) {
    if (color[it] == -1) {
      if (!dfs(it, 1 - col, color, adj))
        return false;
    } else if (color[it] == col)
      return false;
  }
  return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
  int n = edges.size();
  int m = edges[0].size();
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (edges[i][j] == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  vector<int> color(n + 1, -1);
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      //   color[i]= 0;
      if (!dfs(i, 0, color, adj)) {
        return false;
      }
    }
  }
  return true;
}