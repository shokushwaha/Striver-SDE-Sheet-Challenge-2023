
vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here

    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (!st.empty() && st.top() <= curr)
            st.pop();

        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());

        st.push(curr);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}