#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//   if(n == 0) return  0;
//   int longest = 1;
//   set<int> st;
//   for(int it :arr) {
//       st.insert(it);
//   }
//   for(auto it : st) {
//       if(st.find(it-1) == st.end()) {
//           int cnt = 1;
//           int x = it;
//           while(st.find(x+1) != st.end()) {
//               x = x+1;
//               cnt+=1;
//           }
//           longest = max(longest,cnt);
//       }
//   }
//   return longest;

    sort(arr.begin(),arr.end());
    int larget = 1 , cnt = 0;
    int lastSmaller = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i]-1 == lastSmaller) {
            cnt +=1;
            lastSmaller = arr[i];
        } else if(arr[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = arr[i];
        }
        larget = max(larget,cnt);
    }
    return larget;
}