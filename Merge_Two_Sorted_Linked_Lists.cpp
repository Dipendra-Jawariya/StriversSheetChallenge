#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second) {
  Node<int> *temp1 = NULL;
  Node<int> *temp2 = NULL;
  while (first != NULL && second != NULL) {
    int val;
    if (first->data > second->data) {
      val = second->data;
      // cout<<"val"<<val<<endl;
      if (temp1 == NULL) {
        temp1 = new Node<int>(val);
        temp2 = temp1;
      } else {
        temp2->next = new Node<int>(val);
        temp2 = temp2->next;
      }
      second = second->next;
    } else {
      val = first->data;
      if (temp1 == NULL) {
        temp1 = new Node<int>(val);
        temp2 = temp1;
      } else {
        temp2->next = new Node<int>(val);
        temp2 = temp2->next;
      }
      first = first->next;
    }
  }

  while (first != NULL) {
    int val = first->data;
    if (temp1 == NULL) {
      temp1 = new Node<int>(val);
      temp2 = temp1;
    } else {
      temp2->next = new Node<int>(val);
      temp2 = temp2->next;
    }
    first = first->next;
  }

  while (second != NULL) {
    int val = second->data;
    if (temp1 == NULL) {
      temp1 = new Node<int>(val);
      temp2 = temp1;
    } else {
      temp2->next = new Node<int>(val);
      temp2 = temp2->next;
    }
    second = second->next;
  }
  return temp1;
}
