TreeNode<int> *solve(vector<int> &arr, int &i, int bound)
{
    if (i == arr.size() || arr[i] > bound)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(arr[i++]);

    root->left = solve(arr, i, root->data);
    root->right = solve(arr, i, bound);

    return root;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int i = 0;
    int bound = INT_MAX;
    return solve(preOrder, i, bound);
}