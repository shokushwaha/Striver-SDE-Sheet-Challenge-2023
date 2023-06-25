vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.

    vector<pair<int, int>> adj[vertices];
    for (auto it : vec)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> cost(vertices, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cost[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int edgeWeight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int wght = it.second;
            if (edgeWeight + wght < cost[adjNode])
            {
                cost[adjNode] = edgeWeight + wght;
                pq.push({cost[adjNode], adjNode});
            }
        }
    }
    return cost;
}
