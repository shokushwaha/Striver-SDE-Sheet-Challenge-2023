
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if (!root)
        return {};

    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int x = q.size();
        vector<int> temp;
        for (int i = 0; i < x; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            temp.push_back(node->data);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        if (!leftToRight)
            reverse(temp.begin(), temp.end());
        for (auto it : temp)
            ans.push_back(it);

        leftToRight = !leftToRight;
    }
    return ans;
}