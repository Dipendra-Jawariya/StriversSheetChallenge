/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
                {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
#include <bits/stdc++.h>
TreeNode<int> *fun(vector<int> &inOrder, int is, int ie, vector<int> &postOrder,
                   int ps, int pe, map<int, int> &mp) {
  if (ps > pe || is > ie) {
    return NULL;
  }
  TreeNode<int> *root = new TreeNode<int>(postOrder[pe]);
  int inRoot = mp[postOrder[pe]];
  int numsLeft = inRoot - is;
  root->left =
      fun(inOrder, is, inRoot - 1, postOrder, ps, ps + numsLeft - 1, mp);
  root->right =
      fun(inOrder, inRoot + 1, ie, postOrder, ps + numsLeft, pe - 1, mp);
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder,
                                              vector<int> &inOrder) {

  if (postOrder.size() != inOrder.size()) {
    return NULL;
  }
  map<int, int> mp;
  for (int i = 0; i < inOrder.size(); i++) {
    mp[inOrder[i]] = i;
  }
  return fun(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1,
             mp);
}