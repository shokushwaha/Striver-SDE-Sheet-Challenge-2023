void connectNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int x = q.size();
        BinaryTreeNode<int> *prev = NULL;
        for (int i = 0; i < x; i++)
        {
            auto curr = q.front();
            q.pop();

            if (prev != NULL)
                prev->next = curr;

            prev = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
}