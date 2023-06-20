int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp) {
  if (ind == 0) {
    return price[0] * n;
  }
  if (dp[ind][n] != -1)
    return dp[ind][n];
  int notTake = f(ind - 1, n, price, dp);
  int take = INT_MIN;
  int rodlen = ind + 1;
  if (rodlen <= n) {
    take = price[ind] + f(ind, n - rodlen, price, dp);
  }
  return dp[ind][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n) {
  vector<vector<int>> dp(n, vector<int>(n + 1, 0));
  for (int N = 0; N <= n; N++) {
    dp[0][N] = N * price[0];
  }
  for (int ind = 1; ind < n; ind++) {
    for (int N = 0; N <= n; N++) {
      int notTake = dp[ind - 1][N];
      int take = INT_MIN;
      int rodlen = ind + 1;
      if (rodlen <= N) {
        take = price[ind] + dp[ind][N - rodlen];
      }
      dp[ind][N] = max(take, notTake);
    }
  }
  return dp[n - 1][n];
}
