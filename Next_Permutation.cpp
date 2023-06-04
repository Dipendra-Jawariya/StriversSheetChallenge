#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  next_permutation(permutation.begin(),permutation.end());
    // return permutation;
    int ind = -1;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(nums.begin(),nums.end());
        // break;
        return nums;
    }
    for(int i = n-1; i >= ind; i--) {
        if(nums[i] > nums[ind]) {
            swap(nums[i],nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1,nums.end());
    return nums;
    
}