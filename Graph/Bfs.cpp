void bfs(vector<int> adj[], vector<int> &ans, vector<int> &vis, int it)
{
    queue<int> q;
    q.push(it);
    vis[it] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto jt : adj[node])
        {
            if (!vis[jt])
            {
                vis[jt] = 1;
                q.push(jt);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex];

    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    vector<int> vis(vertex, 0);
    vector<int> ans;

    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
            bfs(adj, ans, vis, i);
    }
    return ans;
}