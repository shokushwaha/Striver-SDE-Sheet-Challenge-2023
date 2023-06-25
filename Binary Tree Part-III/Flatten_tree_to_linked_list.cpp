TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
            curr = curr->right;

        else
        {
            TreeNode<int> *prev = curr->left;

            while (prev->right)
                prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
    }
    return root;
}