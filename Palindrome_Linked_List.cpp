#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool palindrome(vector<int>ans){
    int s=0;
    int e=ans.size()-1;
    while(s<=e){
        if(ans[s]!=ans[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(LinkedListNode<int> *head) {

    vector<int>ans;
    LinkedListNode<int> *temp=head;
    while(temp!=NULL){
        ans.push_back(temp->data);
        temp=temp->next;
    }
    return palindrome(ans);
}