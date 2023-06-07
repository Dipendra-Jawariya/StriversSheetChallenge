/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
  int len = 1;
  Node *curr = head;
  while (curr->next != NULL) {
    len++;
    curr = curr->next;
  }
  curr->next = head;
  k = k % len;
  k = len - k;
  for(int i = 0; i < k;i++) {
      head = head->next;
      curr = curr->next;
  }
  curr->next = NULL;
  return head;
}
