void dfsTopo(vector<int> adj[], stack<int> &st, vector<int> &vis, int node)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfsTopo(adj, st, vis, it);
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v];

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    stack<int> st;

    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfsTopo(adj, st, vis, i);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}