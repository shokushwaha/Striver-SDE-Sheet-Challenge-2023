LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL)
        return NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *temp;

    while (curr)
    {
        temp = curr->next;
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = head;

    while (curr)
    {
        curr->next->random = curr->random ? curr->random->next : curr->random;
        curr = curr->next->next;
    }
    curr = head;
    LinkedListNode<int> *original = head;
    LinkedListNode<int> *copy = curr->next;
    temp = copy;
    while (original && copy)
    {
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;

        original = original->next;
        copy = copy->next;
    }
    return temp;
}
