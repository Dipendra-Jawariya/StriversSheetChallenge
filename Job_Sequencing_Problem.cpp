#include <bits/stdc++.h> 
bool comparison(vector<int>a,vector<int> b) {
    return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comparison);
    int n = jobs.size();
    int maxi = jobs[0][1];
    //finding the maximum deadline
    for(int i = 1; i < n; i++) {
        maxi = max(jobs[i][0],maxi);
    }
    vector<int> slot(maxi+1,-1);
    int countJob = 0;
    int profit = 0;
    for(int i = 0; i < n;i++) {
        for(int j = jobs[i][0]; j > 0 ; j--) {
            if(slot[j] == -1) {
                slot[j] = 1;
                countJob++;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
