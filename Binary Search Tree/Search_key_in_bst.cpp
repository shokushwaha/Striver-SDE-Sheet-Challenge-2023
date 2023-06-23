bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.

    BinaryTreeNode<int> *temp = root;

    while (temp)
    {
        if (temp->data == x)
            return true;
        else if (temp->data < x)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}