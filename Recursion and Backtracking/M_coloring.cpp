#include <bits/stdc++.h>
bool isSafe(vector<vector<int>> &graph, vector<int> &color, int node, int n, int col)
{
    for (int i = 0; i < n; i++)
    {
        // node is not the current node and there is a edge between ith node and the current node and there color is same
        if (i != node && graph[i][node] == 1 && color[i] == col)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &graph, vector<int> &color, int m, int n, int node)
{
    // all nodes are coloured
    if (node == n)
        return true;

    // trying all colors for a node
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(graph, color, node, n, col))
        {
            // if color is safe then color it and call for next node
            color[node] = col;
            if (solve(graph, color, m, n, node + 1))
                return true;
            // next node is not safe with the current color hence color it back to 0
            color[node] = 0;
        }
    }

    // after trying all the colors we cannot color the node hence it is impossible to color it
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    vector<int> color(mat.size(), 0);
    if (solve(mat, color, m, mat.size(), 0))
        return "YES";
    return "NO";
}