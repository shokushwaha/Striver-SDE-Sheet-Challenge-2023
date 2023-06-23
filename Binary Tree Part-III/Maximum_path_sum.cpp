int f(TreeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;

    int leftSum = max(0, f(root->left, maxi));
    int rightSum = max(0, f(root->right, maxi));

    maxi = max(maxi, root->val + leftSum + rightSum);

    return root->val + max(leftSum, rightSum);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return -1;
    if (!root->left && !root->right)
        return -1;
    if (!root->left || !root->right)
        return -1;

    int maxi = 0;
    f(root, maxi);
    return maxi;
}