#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    set<string> result;
    int n = word.size();
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            result.insert(word.substr(i,j));
        }
    }
    return result.size();
}
