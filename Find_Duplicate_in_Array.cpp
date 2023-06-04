#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(),arr.end());
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            return arr[i];
        }
    }
    //Better hashing
    //optimal with linked in cycle method
    int fast = nums[0];
    int slow = nums[0];
    do{
        slow = nums[slow];
        fasst = nums[fast];
    } while(slow != fast) {
        slow = nums[slow];
        fast = ums[fast]l
    }
    retur slow;
}
