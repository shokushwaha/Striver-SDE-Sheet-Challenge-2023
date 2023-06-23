TreeNode<int> *build(vector<int> &arr, int low, int high)
{
    if (low > high)
        return NULL;

    int mid = low + (high - low) / 2;

    TreeNode<int> *node = new TreeNode<int>(arr[mid]);

    node->left = build(arr, low, mid - 1);
    node->right = build(arr, mid + 1, high);

    return node;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return build(arr, 0, n - 1);
}