#include <bits/stdc++.h> 
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int count_activity = 1;
    int n = start.size();
    vector<pair<int,int>> vec;
    
    for (int i = 0; i < n; i++) {
        vec.push_back({finish[i],start[i]});
    }
    sort(vec.begin(),vec.end());
    int limit = vec[0].first;
    for(int i = 1; i < n; i++) {
        if(vec[i].second >= limit) {
            limit = vec[i].first;
            count_activity++;

        }
    }
    return count_activity;
}