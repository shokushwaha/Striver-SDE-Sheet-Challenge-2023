bool helper(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int> *> &st)
{
    st.push(root);

    if (!root->left && !root->right)
    {
        if (root->data == leaf->data)
            return true;
        else
        {
            st.pop();
            return false;
        }
    }

    if (root->left)
        if (helper(root->left, leaf, st))
            return true;

    if (root->right)
        if (helper(root->right, leaf, st))
            return true;

    st.pop();
    return false;
}
TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    // Write your code here.
    if (!root)
        return NULL;

    stack<TreeNode<int> *> st;
    bool f = helper(root, leaf, st);

    TreeNode<int> *newRoot = st.top();
    st.pop();
    TreeNode<int> *par = newRoot;
    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr->left == par)
        {
            curr->left = NULL;
            par->left = curr;
        }
        else
        {
            curr->right = curr->left;
            curr->left = NULL;
            par->left = curr;
        }
        par = curr;
    }

    return newRoot;
}
