
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v];

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> degree(v + 1, 0);
    for (auto i : adj)
    {
        for (auto it : i)
        {
            degree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        ans.push_back(p);
        for (auto it : adj[p])
        {
            degree[it]--;
            if (degree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}