int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    TreeNode<int> *curr = root;
    int ans = 0;
    int count = 0;
    while (curr)
    {
        if (curr->left == NULL)
        {
            count++;
            if (count == k)
                ans = curr->data;
            curr = curr->right;
        }
        else
        {
            TreeNode<int> *pre = curr->left;

            while (pre->right && pre->right != curr)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                count++;
                if (count == k)
                    ans = curr->data;
                curr = curr->right;
            }
        }
    }

    return ans;
}