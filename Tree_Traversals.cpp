#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    stack<pair<BinaryTreeNode<int> *,int>> st;
    st.push({root,1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL) {
                st.push({it.first->left,1});
            }
        }
        else if(it.second == 2) {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->right != NULL) {
                st.push({it.first->right,1});
            } 
        }
        else {
            postorder.push_back(it.first->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}