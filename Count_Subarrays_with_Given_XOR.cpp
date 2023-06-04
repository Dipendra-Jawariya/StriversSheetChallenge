#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int xorr = 0;
        for(int j = i; j < n;j++) {
            xorr = xorr ^ arr[j];
            if (xorr == x) cnt++;
        }
    }
    return cnt;
}