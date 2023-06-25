void dfs1(vector<int> adj[], int src, stack<int> &s, vector<int> &vis)
{
    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (!vis[it])
            dfs1(adj, it, s, vis);
    }
    s.push(src);
}

void dfs2(vector<int> adj[], int src, vector<int> &temp, vector<int> &vis)
{
    vis[src] = 1;
    temp.push_back(src);

    for (auto it : adj[src])
    {
        if (!vis[it])
            dfs2(adj, it, temp, vis);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.

    vector<int> adj[n];

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs1(adj, i, s, vis);
    }

    vector<int> adjR[n];

    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (auto it : edges)
    {
        adjR[it[1]].push_back(it[0]);
    }

    vector<vector<int>> ans;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (!vis[node])
        {
            vector<int> temp;
            dfs2(adjR, node, temp, vis);
            ans.push_back(temp);
        }
    }
    return ans;
}