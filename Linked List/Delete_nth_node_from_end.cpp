
int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    if (!head)
        return NULL;

    int cnt = getLength(head);

    if (K > cnt)
        return head;

    if (K == cnt)
        return head->next;

    Node *temp = head;
    int i = 1;
    while (i < cnt - K)
    {
        i++;
        temp = temp->next;
    }
    if (temp->next->next)
        temp->next = temp->next->next;
    else
        temp->next = NULL;

    return head;
}