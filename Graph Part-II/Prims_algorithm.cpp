vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int, int>> adj[n + 1];
    for (auto it : g)
    {
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    vector<int> vist(n + 1, 0);
    vector<pair<pair<int, int>, int>> mst;

    pq.push({{0, 1}, -1});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first.first;
        int node = it.first.second;
        int parent = it.second;

        if (vist[node] == 1)
            continue;
        vist[node] = 1;
        if (parent != -1)
            mst.push_back({{parent, node}, wt});
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgwt = it.second;

            if (!vist[adjNode])
                pq.push({{edgwt, adjNode}, node});
        }
    }

    return mst;
}
