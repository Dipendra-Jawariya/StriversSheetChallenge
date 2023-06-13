#include <bits/stdc++.h>
int singleNonDuplicate(vector<int>& arr)
{
	// map<int,int> mpp;
	// for(auto it : arr) {
	// 	mpp[it]++;
	// }
	// for(auto it : mpp) {
	// 	if(it.second ==1) {
	// 		return it.first;
	// 	}
	// }
	// return -1;

    //1st instance -> even index
    //2nd instance -> odd index, i need to check on the left if the 1st instance of that number is there or not

     int low = 0,high = arr.size()-2;
	 while(low <= high) {
		 int mid = (low + high) /2;
		 if(arr[mid] == arr[mid^1]) {
			 low = mid+1;
		 } else {
			 high = mid-1;
		 }
	 }
	 return arr[low];
}