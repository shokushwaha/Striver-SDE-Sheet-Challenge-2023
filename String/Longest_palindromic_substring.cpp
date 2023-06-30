string longestPalinSubstring(string str)
{
    // Write your code here.

    int low = 0, high = 0;
    int start = 0, end = 1;

    for (int i = 1; i < str.size(); i++)
    {

        // even length string
        low = i - 1;
        high = i;

        while (low >= 0 && high < str.size() && str[low] == str[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }

            low--;
            high++;
        }

        // odd length string
        low = i - 1;
        high = i + 1;

        while (low >= 0 && high < str.size() && str[low] == str[high])
        {
            if (high - low + 1 > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }

    return str.substr(start, end);
}