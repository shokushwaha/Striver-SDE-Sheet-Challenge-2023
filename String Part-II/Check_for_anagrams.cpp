bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    unordered_set<char> st;

    for (auto it : str1)
        st.insert(it);

    for (auto it : str2)
        st.erase(it);

    if (st.size() == 0)
        return true;

    return false;
}