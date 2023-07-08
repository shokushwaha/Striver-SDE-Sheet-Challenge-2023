void pg(vector<int> &prev_s, vector<int> &a)
{
    stack<int> s;
    s.push(0);
    int n = a.size();
    prev_s.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false and a[s.top()] >= a[i])
        {
            s.pop();
        }
        int smaller = s.empty() ? -1 : s.top();
        prev_s.push_back(smaller);
        s.push(i);
    }
}
void ng(vector<int> &next_s, vector<int> &a)
{
    stack<int> s;
    int n = a.size();
    s.push(n - 1);
    next_s.push_back(n);
    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false and a[s.top()] >= a[i])
        {
            s.pop();
        }
        int smaller = s.empty() ? n : s.top();
        next_s.push_back(smaller);
        s.push(i);
    }
    reverse(next_s.begin(), next_s.end());
}
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    vector<int> prev_s;
    vector<int> next_s;
    pg(prev_s, a);
    ng(next_s, a);

    vector<int> ans(n, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        int temp = next_s[i] - prev_s[i] - 2;
        ans[temp] = max(ans[temp], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}