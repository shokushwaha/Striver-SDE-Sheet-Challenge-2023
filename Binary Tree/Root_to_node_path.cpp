
bool f(TreeNode<int> *root, int x, vector<int> &ans)
{
    if (!root)
        return false;

    ans.push_back(root->data);

    if (root->data == x)
    {
        return true;
    }

    if (f(root->left, x, ans))
        return true;

    if (f(root->right, x, ans))
        return true;

    ans.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    f(root, x, ans);
    return ans;
}