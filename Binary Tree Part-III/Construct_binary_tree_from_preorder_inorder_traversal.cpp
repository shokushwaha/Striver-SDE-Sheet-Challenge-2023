TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, int n, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp)
{
    if (preIndex >= n || inorderStart > inorderEnd)
        return NULL;

    int element = preorder[preIndex++];
    TreeNode<int> *root = new TreeNode<int>(element);
    int position = mp[element];

    root->left = solve(inorder, preorder, n, preIndex, inorderStart, position - 1, mp);

    root->right = solve(inorder, preorder, n, preIndex, position + 1, inorderEnd, mp);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int n = inorder.size();
    int preIndex = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;
    TreeNode<int> *ans = solve(inorder, preorder, n, preIndex, 0, n - 1, mp);

    return ans;
}
