vector<int> bottomView(BinaryTreeNode<int> *root)
{
    // Write your code here.
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    vector<int> ans;

    q.push({root, 0});
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        int hd = x.second;
        BinaryTreeNode<int> *node = x.first;

        mp[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}
