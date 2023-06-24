vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    TreeNode *curr = root;
    vector<int> ans;
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
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}