vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.

    if (!root)
        return {};

    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;

    q.push({root, 0});
    vector<int> ans;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        int hd = x.second;
        TreeNode<int> *node = x.first;

        if (mp.find(hd) == mp.end())
            mp[hd] = node->val;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}