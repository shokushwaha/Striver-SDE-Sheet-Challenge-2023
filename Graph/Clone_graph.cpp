unordered_map<graphNode *, graphNode *> mp;
graphNode *dfs(graphNode *curr)
{

    if (mp.find(curr) != mp.end())
        return mp[curr];

    graphNode *clone = new graphNode(curr->data);

    mp[curr] = clone;

    for (auto it : curr->neighbours)
    {
        clone->neighbours.push_back(dfs(it));
    }
    return clone;
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    graphNode *clone = new graphNode(node->data);
    if (node == NULL)
        return NULL;

    if (node->neighbours.size() == 0)
        return clone;

    return dfs(node);
}