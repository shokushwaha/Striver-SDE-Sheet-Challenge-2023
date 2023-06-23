TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    // Write your code here
    if (!root)
        return NULL;

    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->data < P->data && curr->data < Q->data)
            curr = curr->right;

        else if (curr->data > P->data && curr->data > Q->data)
            curr = curr->left;

        else
            return curr;
    }
    return NULL;
}