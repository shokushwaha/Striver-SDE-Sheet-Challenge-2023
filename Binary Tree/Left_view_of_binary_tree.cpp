void f(TreeNode<int> *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    if (root->left)
        f(root->left, ans, level + 1);

    if (root->right)
        f(root->right, ans, level + 1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    f(root, ans, 0);
    return ans;
}