pair<int, pair<int, int>> findLargestBST(TreeNode<int> *root, int &ans)
{

    if (root == NULL)
        return {0, {INT_MAX, INT_MIN}};

    auto leftSubtree = findLargestBST(root->left, ans);
    auto rightSubtree = findLargestBST(root->right, ans);

    if (leftSubtree.second.second < root->data and rightSubtree.second.first > root->data)
    {
        int bstSize = leftSubtree.first + rightSubtree.first + 1;

        ans = max(ans, bstSize);

        return {bstSize, {min(root->data, leftSubtree.second.first), max(root->data, rightSubtree.second.second)}};
    }

    return {0, {INT_MIN, INT_MAX}};
}
int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    int ans = 0;
    findLargestBST(root, ans);
    return ans;
}