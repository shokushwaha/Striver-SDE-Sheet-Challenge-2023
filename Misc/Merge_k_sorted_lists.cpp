class Solution
{
public:
    class comp
    {
    public:
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode *head = new ListNode(-1);
        ListNode *curr = head;

        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;

            if (temp && temp->next)
                pq.push(temp->next);
        }

        return head->next;
    }
};
