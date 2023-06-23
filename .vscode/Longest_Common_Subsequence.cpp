#include <bits/stdc++.h>
int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp) {
  if (ind1 == 0 || ind2 == 0) {
    return 0;
  }
  if (dp[ind1][ind2] != -1)
    return dp[ind1][ind2];
  if (s[ind1 - 1] == t[ind2 - 1]) {
    return 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
  }
  return dp[ind1][ind2] =
             max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
}
int lcs(string s, string t) {
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s[ind1 - 1] == t[ind2 - 1]) {
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      }  else{
          dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
      }
    }
  }
  return dp[n][m];
}