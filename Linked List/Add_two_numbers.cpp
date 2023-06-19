
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.

    Node *head = new Node(-1);
    Node *temp = head;

    int carry = 0;

    while (num1 || num2 || carry != 0)
    {
        int a = 0, b = 0;

        if (num1)
        {
            a = num1->data;
            num1 = num1->next;
        }

        if (num2)
        {
            b = num2->data;
            num2 = num2->next;
        }

        int sum = a + b + carry;
        int digit = sum % 10;
        carry = sum / 10;

        temp->next = new Node(digit);
        temp = temp->next;
    }
    head = head->next;
    return head;
}