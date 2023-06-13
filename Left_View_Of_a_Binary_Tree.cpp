#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
//LEVEL ORDER TRAVERSAl
vector<int> getLeftView(TreeNode<int> *root) {
  vector<int> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode<int> *> q;
  q.push(root);
  vector<int> temp;
  while (!q.empty()) {

    int size = q.size();
    ans.push_back(q.front()->data);
    for (int i = 0; i < size; i++) {

      TreeNode<int> *node = q.front();
      q.pop();
      if (node->left != NULL) {
        q.push(node->left);
      }
      if (node->right != NULL) {
        q.push(node->right);
      }
    }
  }
  return ans;
}

//RECURSIVE ONE
void f(TreeNode<int>  *root, int level, vector<int> &ans) {
  if (root == NULL)
    return;
  if (level == ans.size())
    ans.push_back(root->data);
  f(root->left, level + 1, ans);
  f(root->right, level + 1, ans);
}
vector<int> getLeftView(TreeNode<int> *root) {
  vector<int> ans;
  f(root, 0, ans);
  return ans;
}