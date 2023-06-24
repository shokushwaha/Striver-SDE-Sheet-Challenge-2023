void dfs(vector<int> adj[], vector<int> &temp, vector<int> &vis, int node)
{
    vis[node] = 1;
    temp.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(adj, temp, vis, it);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V, 0);
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(adj, temp, vis, i);
            ans.push_back(temp);
        }
    }
    return ans;
}