void f(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    ans.push_back(root->data);
    f(root->left, ans);
    f(root->right, ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (!root)
        return {};
    vector<int> ans;
    f(root, ans);
    return ans;
}