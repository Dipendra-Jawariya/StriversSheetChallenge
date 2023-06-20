#include <bits/stdc++.h>
long f(int ind,int target,int *arr,
 vector<vector<long>> &dp) {
    if(ind == 0) {
            return (target % arr[0] == 0);
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = f(ind-1,target,arr,dp);
    int pick = 0;
    if(arr[ind] <= target) {
        pick = f(ind,target- arr[ind],arr,dp);
    }
    return dp[ind][target] = (pick + notPick);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}