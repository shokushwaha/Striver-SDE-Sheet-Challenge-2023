bool f(BinaryTreeNode<int> *a, BinaryTreeNode<int> *b)
{
    if (!a && !b)
        return true;

    if (!a || !b)
        return false;

    bool x = a->data == b->data;
    bool y = f(a->left, b->right);
    bool z = f(a->right, b->left);

    return x && y && z;
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return true;
    return f(root->left, root->right);
}