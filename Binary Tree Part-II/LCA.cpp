TreeNode<int> *f(TreeNode<int> *root, int x, int y)
{
    if (!root)
        return NULL;

    if (root->data == x || root->data == y)
        return root;

    TreeNode<int> *leftt = f(root->left, x, y);
    TreeNode<int> *rightt = f(root->right, x, y);

    if (leftt == NULL)
        return rightt;

    if (rightt == NULL)
        return leftt;

    return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here

    TreeNode<int> *ans = f(root, x, y);
    return ans->data;
}