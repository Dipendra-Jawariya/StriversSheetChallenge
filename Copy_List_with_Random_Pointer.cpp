//     }

// LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {

//   LinkedListNode<int> *iter = head;
//   LinkedListNode<int> *front = head;

//   // 1. Create copy nodes
//   while (iter != NULL) {
//     front = iter->next;

//     LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
//     iter->next = copy;
//     copy->next = front;

//     iter = front;
//   }

//   // 2. Point the random pointers
//   iter = head;
//   while (iter != NULL) {
//     if (iter->random != NULL) {
//       iter->next->random = iter->random->next;
//     }
//     iter = iter->next->next;
//   }

//   // 3. restore the original list and extract the copy list
//   iter = head;
//   LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
//   LinkedListNode<int> *copy = dummy;

//   while (iter != NULL) {
//     front = iter->next->next;
//     // extract the copy
//     copy->next = iter->next;
//     // restore the original list
//     iter->next = front;
//     copy = copy->next;
//     iter = front;
//   }
//   return dummy->next;
// }
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head, *temp = NULL;

    // Insert additional node after every node of original list.
    while (curr != NULL)
    {
        temp = curr->next;

        // Inserting node.
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    // Adjust the random pointers of the newly added nodes.
    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            if (curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            else
            {
                curr->next->random = curr->random;
            }
        }

        // Move to the next newly added node by skipping an original node.
        if (curr->next != NULL)
        {
            curr = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }

    LinkedListNode<int> *original = head, *copy = NULL;

    if (head != NULL)
    {
        copy = head->next;
    }

    // Save the start of copied linked list.
    temp = copy;

    // Now separate the original list and copied list.
    while (original != NULL && copy != NULL)
    {
        if (original->next != NULL)
        {
            original->next = original->next->next;
        }

        if (copy->next != NULL)
        {
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }
    return temp;
}