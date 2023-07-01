bool isPossible(int n, int m, vector<int> &time, long long int barrier)
{

    long long int students = 1;
    long long int sum = 0;

    for (int i = 0; i < m; i++)
    {
        if (sum + time[i] <= barrier)
        {
            sum += time[i];
        }
        else
        {
            students++;

            if (students > n || time[i] > barrier)
                return false;

            else
                sum = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long int start = 0;
    long long int end = 0;

    for (auto it : time)
        end += it;

    long long int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}