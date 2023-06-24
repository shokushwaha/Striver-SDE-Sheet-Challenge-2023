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
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        count++;
        for (auto v : adj[it])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    if (count == n)
        return false;
    return true;
}