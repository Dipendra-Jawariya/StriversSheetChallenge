#include <bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int> res;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size();j++) {
            res.push_back(matrix[i][j]);
        }
    }
    sort(res.begin(),res.end());
    int median = (res.size()/2);
    return res[median];
}