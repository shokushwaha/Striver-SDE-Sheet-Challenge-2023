int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int left = 1, right = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        if (left == 0)
            left = 1;

        if (right == 0)
            right = 1;

        left *= arr[i];
        right *= arr[n - i - 1];

        maxi = max(maxi, max(left, right));
    }

    return maxi;
}
