bool dfs(vector<int> &vis, vector<int> adj[], int src, int parent)
{

    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (!vis[it])
            dfs(vis, adj, it, src);
        else if (it != parent)
            return true;
    }

    vis[src] = 0;
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(vis, adj, i, -1))
                return "Yes";
        }
    }
    return "No";
}
