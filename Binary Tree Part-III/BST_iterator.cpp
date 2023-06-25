class BSTiterator
{
private:
    stack<TreeNode<int> *> s;

public:
    void pushAll(TreeNode<int> *root)
    {
        while (root != NULL)
        {

            s.push(root);
            root = root->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code her
        pushAll(root);
    }
    int next()
    {
        // write your code here
        TreeNode<int> *curr = s.top();
        s.pop();
        pushAll(curr->right);
        return curr->data;
    }
    bool hasNext()
    {
        // write your code here
        return !s.empty();
    }
};