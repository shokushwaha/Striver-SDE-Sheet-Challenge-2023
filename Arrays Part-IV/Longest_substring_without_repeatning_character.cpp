int uniqueSubstrings(string input)
{
    // Write your code here

    unordered_map<char, int> mp;
    int len = 0;
    int left = 0, right = 0;
    while (right < input.length())
    {
        if (mp.find(input[right]) != mp.end())
        {
            left = max(left, mp[input[right]] + 1);
        }
        mp[input[right]] = right;
        len = max(len, right - left + 1);

        right++;
    }
    return len;
}