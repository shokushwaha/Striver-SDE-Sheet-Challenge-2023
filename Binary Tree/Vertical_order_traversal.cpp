vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if (!root)
        return {};

    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    vector<int> ans;
    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        TreeNode<int> *node = x.first;
        int hd = x.second;

        mp[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto it : mp)
    {
        for (auto jt : it.second)
            ans.push_back(jt);
    }

    return ans;
}