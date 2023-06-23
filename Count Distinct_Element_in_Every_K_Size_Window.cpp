#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    for(int i = 0;  i< arr.size()-k+1; i++) {
        int dist = 0;
        set<int> st;
        for(int j = i; j < i+k; j++) {
            st.insert(arr[j]);
        }
        dist = st.size();
        ans.push_back(dist);
    }
	return  ans;
}


#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) {
  vector<int> ans;
  int i = 0, j = 0, n = arr.size();
  unordered_map<int, int> mp;

  while (j < n) {
    mp[arr[j]]++;
    if (j - i + 1 < k)
      j++;
    else if (j - i + 1 == k) {
      ans.push_back(mp.size());
      
      mp[arr[i]]--;
      if (mp[arr[i]] == 0)
        mp.erase(arr[i]);
      
      i++, j++;
    }
  }

  return ans;
}