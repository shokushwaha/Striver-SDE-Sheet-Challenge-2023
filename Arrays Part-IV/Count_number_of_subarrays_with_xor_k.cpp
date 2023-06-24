int subarraysXor(vector<int> &A, int B)
{
    //    Write your code here.
    unordered_map<int, int> visited;
    int cpx = 0;
    long long c = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cpx ^= A[i];
        if (cpx == B)
            c++;
        int h = cpx ^ B;
        if (visited.find(h) != visited.end())
        {
            c = c + visited[h];
        }
        visited[cpx]++;
    }
    return c;
}