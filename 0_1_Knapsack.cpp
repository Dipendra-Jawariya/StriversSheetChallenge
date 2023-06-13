#include <bits/stdc++.h>
int f(int ind,int w,vector<int> &values, vector<int> &wt,
		vector<vector<int>> &dp) {
	if(ind == 0) {
		if(wt[ind] <= w) {
			return values[0];
		}
		return 0;
	}
	if(dp[ind][w] != -1) return dp[ind][w];
	int notPick = 0 + f(ind-1,w,values,wt,dp);
	int pick = INT_MIN;
	if(wt[ind] <= w) {
		pick = values[ind] + f(ind-1,w-wt[ind],values,wt,dp);
	}
	return dp[ind][w] = max(pick,notPick);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return f(n-1,w,values,weights,dp);
}