int romanToInt(string s)
{
    // Write your code here
    int sum = 0;
    unordered_map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < s.length(); i++)
        mp[s[i]] < mp[s[i + 1]] ? sum -= mp[s[i]] : sum += mp[s[i]];
    return sum;
}