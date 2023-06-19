#include <bits/stdc++.h> 
int f (int ind,int prev,vector<int> &rack,int n,vector<vector<int>> &dp) {
    if(ind == n) {
        return 0;
    }
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    int notTake = f(ind+1,prev,rack,n,dp);
    int take = INT_MIN;
    if(prev == -1 || rack[prev] < rack[ind]) {
        take = rack[ind] + f(ind+1,ind,rack,n,dp);
    }
    return dp[ind][prev+1] = max(take,notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(0,-1,rack,n,dp);
}