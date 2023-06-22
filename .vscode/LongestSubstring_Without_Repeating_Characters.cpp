#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int left = 0;
    int right = 0;
    set<int> st;
    int len = 0;
    int n = input.size();
    while(right < n) {
        if(st.find(input[right]) == st.end() ) {
            st.insert(input[right]);
            right++; 
        } else {
            // while(left < right && st.find(input[i]) != st.end()) {
                st.erase(input[left]);
                left++;
            // }
        }
        len = max(len,right - left);
    }
    return len;
} 
#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    int left = 0,right = 0;
    int n = input.size();
    int len = 0;
    vector<int> mpp(256,-1);
    while(right < n) {
        if(mpp[input[right]] != -1) {
            left = max(mpp[input[right]] + 1,left);
        }
        mpp[input[right]] = right;
        len = max(len,right-left+1);
        right++;
    }
    return len;
}