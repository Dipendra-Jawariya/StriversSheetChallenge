#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n == 1) return "1";
    if(n == 2) return "11";
    string s = "11";
    for(int i = 3; i <= n; i++) {
        string newStr = "";
        s = s + '&';
        int cnt = 1;
        for(int j = 1; j < s.size(); j++) {
            if(s[j] != s[j-1]) {
                newStr = newStr + to_string(cnt);
                newStr = newStr + s[j-1];
                cnt = 1;
            } else cnt++;
        }
        s = newStr;
    }
    return s;
}