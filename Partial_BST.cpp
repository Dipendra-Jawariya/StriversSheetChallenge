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
bool isValidBST(BinaryTreeNode<int> *root,int minVal,int maxVal) {
    if(root == NULL) return true;
    if(root->data >= maxVal || root->data <= minVal) return false;
    return isValidBST(root->left,minVal,root->data) && 
        isValidBST(root->right,root->data,maxVal);
}
bool validateBST(BinaryTreeNode<int> *root) {
     return isValidBST(root,-1e9, 1e9);
}