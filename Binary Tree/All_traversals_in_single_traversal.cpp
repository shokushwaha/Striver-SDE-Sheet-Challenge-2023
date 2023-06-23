void f(BinaryTreeNode<int> *root, vector<int> &pre, vector<int> &ino, vector<int> &pos)
{
    if (!root)
        return;
    pre.push_back(root->data);
    f(root->left, pre, ino, pos);
    ino.push_back(root->data);
    f(root->right, pre, ino, pos);
    pos.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> pre;
    vector<int> ino;
    vector<int> pos;
    f(root, pre, ino, pos);
    vector<vector<int>> ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}