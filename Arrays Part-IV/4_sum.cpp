string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int k = j + 1, l = n - 1;
            int sum = arr[i] + arr[j];
            int tar = target - sum;
            while (k < l)
            {
                if (arr[k] + arr[l] == tar)
                    return "Yes";
                else if (arr[k] + arr[l] < tar)
                    k++;
                else
                    l--;
            }
        }
    }
    return "No";
}
