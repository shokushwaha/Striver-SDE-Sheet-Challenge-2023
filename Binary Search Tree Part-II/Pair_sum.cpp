void inOrder(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BinaryTreeNode<int> *curr = root;
    vector<int> arr;
    inOrder(root, arr);
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == k)
            return true;
        else if (sum < k)
            i++;
        else
            j--;
    }
    return false;
}