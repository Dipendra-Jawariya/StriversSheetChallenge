#include <bits/stdc++.h>

int kthlargest(vector<int> &arr, int l, int r, int k) {
  if (l == r)
    return arr[l];
  int p = l;
  int pivot = arr[r];
  for (int i = l; i < r; i++) {
    if (arr[i] < pivot) {
      swap(arr[i], arr[p++]);
    }
  }
  swap(arr[r], arr[p]);
  if (p >= k)
    return kthlargest(arr, l, p - 1, k);
  if (p < k - 1)
    return kthlargest(arr, p + 1, r, k);
  else
    return arr[p];
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
  //   vector<int> res;
  //   priority_queue<int> pq;
  //   priority_queue<int, vector<int>, greater<int>> pq1;
  //   for (int i = 0; i < n; i++) {
  //     pq.push(arr[i]);
  //     pq1.push(arr[i]);
  //     if (pq.size() > k)
  //       pq.pop();
  //     if (pq1.size() > k)
  //       pq1.pop();
  //   }
  //   return {pq.top(), pq1.top()};

  vector<int> ans;
  ans.push_back(kthlargest(arr, 0, n - 1, k));
  ans.push_back(kthlargest(arr, 0, n - 1, n - k + 1));
  return ans;
}