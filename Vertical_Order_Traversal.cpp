#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root) {
  vector<int> ans;
  map<int, map<int, vector<int>>> m;
  queue<pair<TreeNode<int> *, pair<int, int>>> q;
  q.push({root, {0, 0}});
  while (!q.empty()) {
    auto temp = q.front();
    q.pop();
    TreeNode<int> *node = temp.first;
    int v = temp.second.first, h = temp.second.second;
    m[v][h].push_back(node->data);
    if (node->left)
      q.push({node->left, {v - 1, h + 1}});
    if (node->right)
      q.push({node->right, {v + 1, h + 1}});
  }
  for (auto i : m) {
    for (auto j : i.second) {
      for (auto k : j.second) {
        ans.push_back(k);
      }
    }
  }

  return ans;
}