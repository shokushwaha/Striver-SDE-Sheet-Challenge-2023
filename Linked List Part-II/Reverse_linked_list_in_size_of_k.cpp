Node *reversal(Node *head, int n, int b[], int i)
{
    while (b[i] == 0 && i < n)
        i++;

    if (!head || !head->next || i == n)
        return head;

    int counter = b[i];
    Node *prev = NULL, *curr = head, *nxt;
    while (curr != NULL && counter--)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head->next = reversal(nxt, n, b, i + 1);
    return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    if (!head)
        return NULL;

    return reversal(head, n, b, 0);
}