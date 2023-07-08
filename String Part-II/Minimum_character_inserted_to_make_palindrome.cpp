int minCharsforPalindrome(string str)
{
    // Write your code here.
    int ans = 0;
    int i = 0;
    int j = str.size() - 1;
    int trim = j;

    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            ans++;
            i = 0;
            j = --trim;
        }
    }

    return ans;
}
