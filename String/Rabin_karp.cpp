#define M 1000000007

long long power(long long x)
{
    long long ans = 1;
    while (x > 0)
    {
        x--;
        ans = ((ans % M) * 26) % M;
    }
    return ans % M;
}

vector<int> stringMatch(string text, string pattern)
{
    vector<int> ans;

    // hash function
    long long m = pattern.length(), n = text.length();

    long long hash_pattern = 0, hash_string = 0;
    for (long long i = m - 1; i >= 0; --i)
    {
        hash_pattern = ((hash_pattern % M) + ((pattern[i] - 'a' + 1) * power(m - i - 1)) % M) % M;
        hash_string = (hash_string + ((text[i] - 'a' + 1) * (power(m - i - 1) % M)) % M) % M;
    }

    for (long long i = m; i < n; ++i)
    {
        // cout<<hash_pattern<<' '<<hash_string<<endl;
        if (hash_string == hash_pattern)
        {
            // cout<<1<<endl;
            ans.push_back(i - m + 1);
        }

        hash_string = (M + hash_string - ((text[i - m] - 'a' + 1) * (power(m - 1) % M)) % M) % M;
        hash_string = (hash_string * 26) % M;
        hash_string = (hash_string + (text[i] - 'a' + 1) % M) % M;
    }
    // cout<<hash_pattern<<' '<<hash_string<<endl;
    if (hash_string == hash_pattern)
    {
        ans.push_back(n - m + 1);
    }

    return ans;
}