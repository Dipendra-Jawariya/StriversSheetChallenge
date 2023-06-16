#include <bits/stdc++.h>
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == x) {
    return root;
  }
  if (x < root->data) {
    return searchInBST(root->left, x);
  }
  return searchInBST(root->right, x);
//   while (root != NULL && root->data != x) {
//     root = x < root->data ? root->left : root->right;
//   }
//   return root->data == x;
}