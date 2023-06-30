int atoi(string str)
{
    // Write your code here.
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '-')
            sign = -1;
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            result = result * 10 + str[i] - '0';
        i++;
    }
    return result * sign;
}