/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL || secondHead == NULL) {
      return NULL;
    }
    Node * headA = firstHead;
    Node *headB = secondHead;
    while(headA!= headB) {
      headA = headA == NULL ? firstHead : headA -> next;
      headB = headB == NULL ? secondHead : headB -> next;
    }
    return headA;
}
