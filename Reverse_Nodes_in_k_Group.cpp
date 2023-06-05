Node *krevgroup(Node *head, int n, int b[], int i)
{
    
    if (n<1 || head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = NULL;
    int cnt = 0;
   
    while(b[i] == 0 && i < n) i++;
    while (curr != NULL && cnt < b[i] && i < n  )
    {
        nxt = curr->next;
         curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
   
    if (i >= n && curr != NULL)
    {

        return head;
    }
    if (curr != NULL)
        head->next = krevgroup(nxt, n, b, i + 1);
   
    return prev;
  
    

}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	return krevgroup(head,n,b,0);
}