bool valid(vector<int> &arr, int k, int a)

{

    int n = arr.size();

    int prev = arr[0];

    int cnt = 1;

    for (int i = 1; i < n; i++)

    {

        if (arr[i] - prev >= a)

        {

            cnt++;

            prev = arr[i];
        }
    }

    return cnt >= k;
}

int aggressiveCows(vector<int> &arr, int k)
{
    //    Write your code here.
    sort(arr.begin(), arr.end());

    int n = arr.size();

    int mini = INT_MAX;

    int maxi = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)

        mini = min(mini, arr[i] - arr[i - 1]);

    int ans;

    int low = mini, high = maxi;

    while (low <= high)

    {

        int mid = (low + high) / 2;

        if (valid(arr, k, mid))

        {

            ans = mid;

            low = mid + 1;
        }

        else

            high = mid - 1;
    }

    return ans;
}