#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure.

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
void flatten(TreeNode<int>* root, TreeNode<int>* &prev){
    // Base Case
    if(root == NULL) return;
    // Flatten Right Sub Tree
    flatten(root->right, prev);
    // Flatten Left Sub Tree
    flatten(root->left, prev);
    // Update/Modify
    root->left = NULL;
    root->right = prev;
    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
    TreeNode<int> *prev = NULL;
    flatten(root,prev);
    return root;
}