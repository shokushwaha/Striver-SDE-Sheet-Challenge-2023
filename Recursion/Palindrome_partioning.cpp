bool isPalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void partitionHelper(int ind, vector<vector<string>> &ans, vector<string> &v, string &s)
{
    if (ind == s.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            v.push_back(s.substr(ind, i - ind + 1));
            partitionHelper(i + 1, ans, v, s);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> v;
    int ind = 0;
    partitionHelper(ind, ans, v, s);
    return ans;
}