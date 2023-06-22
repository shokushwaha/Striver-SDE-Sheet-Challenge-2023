vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if (!root)
        return {};

    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int x = q.size();
        for (int i = 0; i < x; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            ans.push_back(node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
}