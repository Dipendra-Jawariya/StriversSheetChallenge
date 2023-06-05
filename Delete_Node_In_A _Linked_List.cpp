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

void deleteNode(LinkedListNode<int> * node) {
    if(node->next == NULL) {
        return;
    }
    LinkedListNode<int> * del = node->next;
    node->data = del->data;
    node->next = del->next;
}