int f(TreeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;
    int left = f(root->left, maxi);
    int right = f(root->right, maxi);
    maxi = max(maxi, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = INT_MIN;
    f(root, maxi);
    return maxi;
}