int f(BinaryTreeNode<int> *root, bool &flag)
{
    if (!root)
        return true;

    int left = f(root->left, flag);
    int right = f(root->right, flag);

    if (abs(left - right) > 1)
        flag = false;

    return 1 + max(left, right);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return true;

    bool flag = true;
    f(root, flag);
    return flag;
}