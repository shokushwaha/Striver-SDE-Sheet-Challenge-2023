string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    if (!root)
        return "";
    string str;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            auto p = q.front();
            q.pop();

            if (!p)
            {
                str += "#,";
                continue;
            }

            str += to_string(p->data) + ",";
            q.push(p->left);
            q.push(p->right);
        }
    }

    return str;
}

TreeNode<int> *deserializeTree(string &str)
{
    //    Write your code here for deserializing the tree
    if (str.empty())
        return NULL;

    stringstream s(str);
    string temp;

    getline(s, temp, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(temp));

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        getline(s, temp, ',');
        if (temp == "#")
            p->left = NULL;
        else
        {
            p->left = new TreeNode<int>(stoi(temp));
            q.push(p->left);
        }

        getline(s, temp, ',');
        if (temp == "#")
            p->right = NULL;
        else
        {
            p->right = new TreeNode<int>(stoi(temp));
            q.push(p->right);
        }
    }

    return root;
}
