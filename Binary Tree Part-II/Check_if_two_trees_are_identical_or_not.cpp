bool f(BinaryTreeNode<int> *a, BinaryTreeNode<int> *b)
{
    if (!a && !b)
        return true;

    if (!a || !b)
        return false;

    bool x = a->data == b->data;
    bool y = f(a->left, b->left);
    bool z = f(a->right, b->right);

    return x && y && z;
}
bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    // Write your code here.
    return f(root1, root2);
}