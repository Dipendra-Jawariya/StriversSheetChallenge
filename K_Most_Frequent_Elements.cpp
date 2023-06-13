#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr) {
  map<int, int> mpp;
  for (int it : arr) {
    mpp[it]++;
  }
  priority_queue<pair<int, int>> pq;
  for (auto it : mpp) {
    pq.push({it.second, it.first});
  }
  vector<int> ans;
  for (int i = 1; i <= k; i++) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  sort(ans.begin(),ans.end());
  return ans;
}