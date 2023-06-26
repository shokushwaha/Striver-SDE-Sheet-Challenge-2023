class DisjointSet
{

private:
    vector<int> rank, parent, size;

public:
    // consturctror
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // parent and path compression
    int findPar(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = findPar(parent[x]);
    }

    // union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    // union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
bool static comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    // Write your code here.
    DisjointSet dS(n);
    int sum = 0;
    sort(graph.begin(), graph.end(), comp);
    for (auto it : graph)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dS.findPar(u) != dS.findPar(v))
        {
            sum += wt;
            dS.unionByRank(u, v);
        }
    }
    return sum;
}