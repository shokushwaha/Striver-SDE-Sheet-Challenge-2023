bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[src] = 1;
    pathVis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it])
            return true;
    }
    pathVis[src] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.

    vector<int> adj[n + 1];
    int indegree[n + 1] = {0};
    for (auto p : edges)
    {
        adj[p.first].push_back(p.second);
        indegree[p.second]++;
    }
    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}