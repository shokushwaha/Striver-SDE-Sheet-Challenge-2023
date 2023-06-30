int zAlgorithm(string s, string p, int n, int m)
{
    // Write your code here

    int cnt = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (s[i] == p[0])
        {
            if (s.substr(i, m) == p)
                cnt++;
        }
    }
    return cnt;
}