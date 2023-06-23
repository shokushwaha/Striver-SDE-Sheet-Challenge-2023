int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return 0;
    queue<TreeNode<int> *> q;
    int ans = 0;
    q.push(root);
    while (!q.empty())
    {
        int x = q.size();
        ans = max(ans, x);
        for (int i = 0; i < x; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return ans;
}