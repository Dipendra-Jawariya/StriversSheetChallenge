#include <bits/stdc++.h>
void dfsTopo(int node,vector<int> &vis,stack<int> &st,vector<vector<int>> &adj) {
    vis[node] = 1;

    for(int it : adj[node]) {
        if(vis[it] != 1) {
            dfsTopo(it,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  vector<vector<int>> adj(v + 1);
  int m = edges.size();
  for (int i = 0; i < m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
  }
  vector<int> vis(v,0);
  stack<int> st;
  for(int i = 0; i < v; i++) {
      if(!vis[i]) {
          dfsTopo(i,vis,st,adj);
      }
  }
  vector<int> ans;
  while(!st.empty()) {
      ans.push_back(st.top());
      st.pop();
  }
  return ans;
}