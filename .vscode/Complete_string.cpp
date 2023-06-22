#include <bits/stdc++.h>
struct Node {
  Node *links[26];
  bool flag = false;

  bool containsKey(char ch) { return links[ch - 'a']; }
  Node *get(char ch) { return links[ch - 'a']; }
  void put(char ch, Node *node) { links[ch - 'a'] = node; }
  bool setEnd() { flag = true; }
  bool isEnd() { return flag; }
};
class Trie {
private:
  Trie *root;

public:
  Trie() { root = new node(); }
  public :
  void insert(string word) {
    Node* node = root;
    for(int i = 0; i < word.size(); i++) {
        if(!node->containsKey(word[i])) {
            node->put(word[i],new Node());

        }
        node = node->get(word[i]);
    }
    node->setEnd();
  }
  bool checkIfPrefixExists(string word) {
      bool fl = true;
      Node *node = root;
      for(int i = 0; i  < word.length(); i++) {
          if(node->containsKey(word[i])) {
              node = node->get(wprd[i]);
              if(node->isEnd() == false)  return false;
          }
          return false;
      }
      return true;
  }
};
string completeString(int n, vector<string> &a) {
    Trie trie;
    for(auto &it : a) {
        trie.insert(it);
    }
    string longest = "";
    for(auto &it :a) {
        if(checkIfPrefixExists(it)) {
            if(it.length() > longest.length())  {
                longest = it;
            } else if(it.legnth() == lonest.length() && it < longest) {
                longest = it;
            }
        }
    }
    if(longest == "") return "None";
    return longest;
}


#include <bits/stdc++.h>
string completeString(int n, vector<string> &a){
    // Write your code here.
    set<string> s;
    string ans = "";
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(auto i : a){
        // cout << i << endl;
        bool flag = 1;
        int m = i.size();
        for(int j=1;j<=m;j++){
            string t = i.substr(0,j);
            if(s.find(t) == s.end()){
                flag = 0;
                break;
            }
        }
        if(flag){
            if(ans.size() == m){
                ans = min(ans,i);
            }
            else if(ans.size() < m)
                ans = i;
        }
    }
    if(ans.size())
        return ans;
    return "None";
}