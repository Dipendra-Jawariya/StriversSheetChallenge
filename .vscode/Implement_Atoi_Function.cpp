#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    for(auto it : str) {
        int n = it - '0';
        if(isdigit(it)) {
            ans *= 10;
            ans += n;
        }
    }
    if(str[0] == '-') {
        return -(ans);
    }
    return ans;
}