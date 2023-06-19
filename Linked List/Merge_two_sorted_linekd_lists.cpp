Node<int> *merge(Node<int> *a, Node<int> *b)
{
    Node<int> *head = new Node<int>(-1);
    Node<int> *temp = head;

    while (a && b)
    {
        if (a->data < b->data)
        {
            Node<int> *x = new Node<int>(a->data);
            temp->next = x;
            temp = temp->next;
            a = a->next;
        }

        else
        {
            Node<int> *x = new Node<int>(b->data);
            temp->next = x;
            temp = temp->next;
            b = b->next;
        }
    }
    while (a)
    {
        Node<int> *x = new Node<int>(a->data);
        temp->next = x;
        temp = temp->next;
        a = a->next;
    }
    while (b)
    {
        Node<int> *x = new Node<int>(b->data);
        temp->next = x;
        temp = temp->next;
        b = b->next;
    }
    return head->next;
}
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    return merge(first, second);
}