#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int> * prev = NULL;

    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            BinaryTreeNode<int> * curr = q.front();
            q.pop();
            if(prev != NULL) {
                prev->next = curr;
            }
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            prev = curr;
        }
        prev = NULL;
    }
}