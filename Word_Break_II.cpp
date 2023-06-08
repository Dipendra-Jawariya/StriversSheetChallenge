#include <bits/stdc++.h>

void f(int in, string str, map<string, int> &m, string &s, vector<string> &ans) {
  if (in == s.size()) {
    ans.push_back(str);
    return;
  }
  for (int i = in; i < s.size(); i++) {
    string tmp = s.substr(in, i - in + 1);
    if (m[tmp] >= 1) {
      int n = str.size();
      str += tmp + " ";
      f(i + 1, str, m, s, ans);
      str.erase(n);
    }
  }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)

{

  vector<string> ans;
  map<string, int> m;
  for (int i = 0; i < dictionary.size(); i++) {
    m[dictionary[i]]++;
  }
  f(0, "", m, s, ans);
  return ans;
}