class Solution
{
public:
    int findMaxTime(map<Node *, Node *> &m, Node *target)
    {

        map<Node *, int> vis;
        queue<Node *> q;
        q.push(target);
        vis[target] = 1;
        int maxi = 0;
        while (!q.empty())
        {
            int sz = q.size();
            int fl = 0;
            for (int i = 0; i < sz; i++)
            {
                auto x = q.front();
                q.pop();

                if (x->left && !vis[x->left])
                {
                    q.push(x->left);
                    vis[x->left] = 1;
                    fl = 1;
                }

                if (x->right && !vis[x->right])
                {
                    q.push(x->right);
                    vis[x->right] = 1;
                    fl = 1;
                }

                if (m[x] && !vis[m[x]])
                {
                    q.push(m[x]);
                    vis[m[x]] = 1;
                    fl = 1;
                }
            }

            if (fl)
                maxi++;
        }
        return maxi;
    }

    Node *parentMap(Node *root, map<Node *, Node *> &m, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *res = NULL;

        while (!q.empty())
        {
            Node *x = q.front();
            q.pop();

            if (x->data == target)
                res = x;

            if (x->left)
            {
                q.push(x->left);
                m[x->left] = x;
            }

            if (x->right)
            {
                q.push(x->right);
                m[x->right] = x;
            }
        }
        return res;
    }

    int minTime(Node *root, int tar)
    {
        // Your code goes here
        map<Node *, Node *> m;

        Node *target = parentMap(root, m, tar);

        int maxi = findMaxTime(m, target);

        return maxi;
    }
};