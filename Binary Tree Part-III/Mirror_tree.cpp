void reorder(Node *root)
{
    if (!root)
        return;

    reorder(root->left);
    reorder(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
// Function to convert a binary tree into its mirror tree.
void mirror(Node *node)
{
    // code here
    reorder(node);
}