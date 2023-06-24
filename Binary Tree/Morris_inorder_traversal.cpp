vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if (!root)
        return {};
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                ans.push_back(curr->data);
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}