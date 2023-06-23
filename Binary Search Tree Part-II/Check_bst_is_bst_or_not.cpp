bool f(BinaryTreeNode<int> *root, int mini, int maxi)
{
    if (!root)
        return true;

    bool x = root->data >= mini && root->data <= maxi;
    bool y = f(root->left, mini, root->data);
    bool z = f(root->right, root->data, maxi);
    return x && y && z;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return f(root, INT_MIN, INT_MAX);
}