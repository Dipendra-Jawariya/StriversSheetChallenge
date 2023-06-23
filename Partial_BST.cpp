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




// #include <bits/stdc++.h>

// bool validateBST(BinaryTreeNode<int> *root) {
//   // Write your code here
//   if (root == NULL || (root->left == NULL && root->right == NULL))
//     return true;

//   bool left = validateBST(root->left);
//   bool right = validateBST(root->right);

//   bool ans = true;

//   if (root->left)
//     ans = ans && (root->data >= root->left->data);

//   if (root->right)
//     ans = ans && (root->data <= root->right->data);

//   return ans && left && right;
// }