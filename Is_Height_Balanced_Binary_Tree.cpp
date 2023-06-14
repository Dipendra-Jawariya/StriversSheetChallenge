#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
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

*************************************************************/

int height(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    if(lh == -1) return -1;
    int rh = height(root->right);
    if(rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return 1+max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return height(root) != -1;
}