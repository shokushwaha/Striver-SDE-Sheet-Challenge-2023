void f(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    f(root->left, ans);
    ans.push_back(root->data);
    f(root->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (!root)
        return {};
    vector<int> ans;
    f(root, ans);
    return ans;
}