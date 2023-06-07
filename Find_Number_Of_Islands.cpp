void dfs(int row, int col, vector<vector<int>> &vis, int **arr,int n,int m ) {
   
  vis[row][col] = 1;
  

   int delrow[] = { -1, 0, 1, 0 ,-1,1,-1,1};
   int delcol[] = { 0, 1, 0, -1 ,1,-1,-1,1};

  for (int i = 0; i < 8; i++) {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];
    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
        arr[nrow][ncol] == 1) {
      dfs(nrow, ncol, vis, arr,n,m);
    }
  }
}
int getTotalIslands(int **arr, int n, int m) {
  int island = 0;
  vector<vector<int>> vis(n, vector<int>(m,0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && arr[i][j] == 1) {
        dfs(i, j,vis, arr,n,m);
        island++;
      }
    }
  }
  return island;
}
