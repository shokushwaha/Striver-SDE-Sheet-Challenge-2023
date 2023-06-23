int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    TreeNode<int> *curr = root;
    int floor = 0;
    while (curr)
    {
        if (curr->val == X)
            return curr->val;

        else if (curr->val < X)
        {
            floor = curr->val;
            curr = curr->right;
        }
        else
            curr = curr->left;
    }
    return floor;
}