int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    if (!node)
        return -1;
    int ceil = -1;
    BinaryTreeNode<int> *curr = node;
    while (curr)
    {
        if (curr->data == x)
            return curr->data;

        else if (curr->data > x)
        {
            ceil = curr->data;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    return ceil;
}