vector<int> nextSmaller(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmaller(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}