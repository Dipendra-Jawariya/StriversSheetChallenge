#include <bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
  stack<pair<int, int>> st;
  vector<int> ans(price.size());

  for (int i = 0; i < price.size(); i++) {
    int span = 1;
    while (st.size() and st.top().first <= price[i]) {
      span += st.top().second;
      st.pop();
    }
    st.push({price[i], span});
    ans[i] = span;
  }
  return ans;
}