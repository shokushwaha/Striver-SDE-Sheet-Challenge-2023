bool detectCycle(Node *head)
{
    //	Write your code here
    Node *slow = head;
    Node *fast = head->next;

    while (slow && fast && fast->next)
    {
        if (slow == fast)
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}