ssstring f(int n)
{
    if (n == 1)
        return "1";

    string temp = f(n - 1);
    string res = "";

    for (int i = 0; i < temp.size(); i++)
    {
        int cnt = 1;

        while (i < temp.size() && temp[i] == temp[i + 1])
        {
            i++;
            cnt++;
        }

        res += to_string(cnt);
        res += temp[i];
    }
    return res;
}
string writeAsYouSpeak(int n)
{
    // Write your code here.
    return f(n);
}