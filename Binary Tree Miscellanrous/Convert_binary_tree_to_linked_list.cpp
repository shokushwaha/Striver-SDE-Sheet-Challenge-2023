void f(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;

    f(root->left, ans);
    ans.push_back(root->data);
    f(root->right, ans);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<int> inorder;
    f(root, inorder);

    BinaryTreeNode<int> *head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int> *curr = head;
    BinaryTreeNode<int> *prev = NULL;

    for (auto it : inorder)
    {
        BinaryTreeNode<int> *x = new BinaryTreeNode<int>(it);
        curr->right = x;
        curr->left = prev;
        prev = curr;
        curr = curr->right;
    }
    curr->right = NULL;
    return head->right;
}