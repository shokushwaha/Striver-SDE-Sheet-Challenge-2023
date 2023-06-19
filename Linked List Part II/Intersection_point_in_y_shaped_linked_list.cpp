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
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here

    int len1 = getLength(firstHead);
    int len2 = getLength(secondHead);

    int dif = abs(len1 - len2);

    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    for (int i = 0; i < dif; i++)
    {
        if (len1 < len2)
            temp2 = temp2->next;
        else
            temp1 = temp1->next;
    }

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
}