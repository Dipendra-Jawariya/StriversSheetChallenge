#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> hash(n+1,0);
	for(int i = 0; i < n; i++) {
		hash[arr[i]]++;
	}
	int missing,dup;
	for(int i = 1; i <= n; i++) {
		if(hash[i] == 0) missing = i;
		if(hash[i] > 1) dup = i;
	}
	return {missing,dup};
}
