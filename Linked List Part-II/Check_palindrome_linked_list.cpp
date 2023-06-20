LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head, *nxt = NULL, *prev = NULL;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.

    if (!head)
        return true;

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseLinkedList(slow->next);
    slow = slow->next;

    LinkedListNode<int> *temp = head;
    while (slow)
    {
        if (slow->data != temp->data)
            return false;

        slow = slow->next;
        temp = temp->next;
    }
    return true;
}