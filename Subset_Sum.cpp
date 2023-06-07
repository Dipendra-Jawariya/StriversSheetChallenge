#include <bits/stdc++.h> 
void f(int ind,vector<int> &num,int sum,vector<int> &ds,int n) {
    if(ind == n) {
        ds.push_back(sum);
        return;
    }
    f(ind+1,num,sum+num[ind],ds,n);
    f(ind+1,num,sum,ds,n);
}
vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    vector<int> ds;
    f(0,num,0,ds,n);
    sort(ds.begin(),ds.end());
    return ds;
}