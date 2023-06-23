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
