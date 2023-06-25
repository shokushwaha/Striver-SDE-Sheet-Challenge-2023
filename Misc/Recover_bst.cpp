class Solution
{
private:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;

public:
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        if (prev != NULL && prev->val > root->val)
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if (first && last)
        {
            swap(first->val, last->val);
        }

        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};