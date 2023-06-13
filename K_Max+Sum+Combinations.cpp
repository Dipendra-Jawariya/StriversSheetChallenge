#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	//BRUTE FORCE
	// vector<int> ans;
	// if(n < k) return ans;

	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		ans.push_back(a[i]+b[j]);
	// 	}
	// }
	// vector<int> res;
	// sort(ans.begin(),ans.end(),greater<int>()) ;
	// for(int i = 0; i < k; i++) {
	// 	res.push_back(ans[i]);
	// }
	// return res;

    // BETTER
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	//Using a max-heap.
	priority_queue<pair<int,pair<int,int>>> maxHeap;
	maxHeap.push({a[n-1]+b[n-1],{n-1,n-1}});

	set<pair<int,int>> set;
	set.insert({n-1,n-1});
	vector<int> res;
	
	while(k > 0) {
		pair<int,pair<int,int>> top = maxHeap.top();
		maxHeap.pop();
		int sum = top.first;
		int x = top.second.first;
		int y = top.second.second;
		res.push_back(sum);
	//check if index combo does exist
		if(set.find({x-1,y}) == set.end()) {
			maxHeap.push({a[x-1]+b[y], {x-1,y}});
			set.insert({x-1,y});
		}
		if(set.find({x,y-1}) == set.end()) {
			maxHeap.push({a[x]+b[y-1], {x,y-1}});
			set.insert({x,y-1});
		}
		k--;
	}
	return res;
}