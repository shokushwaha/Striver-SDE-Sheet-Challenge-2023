void getLength(TreeNode<int> *root, int &len)
{
    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            len++;
            curr = curr->right;
        }

        else
        {
            TreeNode<int> *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                len++;
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}
int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    int ans = -1;
    int len = 0;
    getLength(root, len);
    int cnt = 0;

    TreeNode<int> *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cnt++;
            if (cnt == len - k + 1)
                ans = curr->data;
            curr = curr->right;
        }

        else
        {
            TreeNode<int> *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                cnt++;
                if (cnt == len - k + 1)
                    ans = curr->data;
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}
