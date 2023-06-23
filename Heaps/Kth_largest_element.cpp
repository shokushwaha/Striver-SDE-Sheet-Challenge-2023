vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    sort(arr.begin(), arr.end());

    int max = arr[k - 1];
    int min = arr[n - k];

    vector<int> v;
    v.push_back(max);
    v.push_back(min);
    return v;
}