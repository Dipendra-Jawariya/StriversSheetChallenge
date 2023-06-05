/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    int len = 0;
    for(Node* curr = head;curr != NULL; curr = curr->next) {
        len++;
    }
    if(len == K) return head->next;
    Node* curr = head;
    for(int i = 0; i < (len-K)-1; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}
