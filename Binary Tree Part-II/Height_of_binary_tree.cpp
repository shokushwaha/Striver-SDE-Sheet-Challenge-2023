int f(TreeNode *root)
{
    if (!root)
        return 0;

    int left = f(root->left);
    int right = f(root->right);

    return 1 + max(left, right);
}
int height(TreeNode *root)
{
    return f(root);
}