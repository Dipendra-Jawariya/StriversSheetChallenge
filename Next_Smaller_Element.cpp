#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n) {
  vector<int> ans(n, -1);
  stack<int> st;
  // st.push(arr[n-1]);
  // ans[n-1] = -1;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() >= arr[i]) {
      st.pop();
    }
    if (!st.empty()) {
      ans[i] = st.top();
    } else {
      ans[i] = -1;
    }
    st.push(arr[i]);
  }
  return ans;
}