// pattern matching algorithint zAlgorithm(string s, string p, int n, int m)
{
	int cnt = 0;
	for(int i = 0; i < n-m+1; i++) {
		if(s[i] == p[0]) {
			if(s.substr(i,m) == p) {
				cnt++;
			}
		}
	}
	return cnt;
}

//using z_function
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
	string str = s + '$' + p;
	vector<int> z = z_function(str);
	int cnt = 0;
	for(int i = 0; i < z.size(); i++) {
		if(z[i] == p.size()) {
			 cnt++;
		}
	}
	return cnt;
}