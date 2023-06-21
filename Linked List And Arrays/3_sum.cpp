#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.

    if (n < 3)
        return {};

    vector<vector<int>> triplets;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;

        while (start < end)
        {
            int sum = arr[i] + arr[start] + arr[end];
            if (sum == K)
            {
                triplets.push_back({arr[i], arr[start], arr[end]});
                start++;
                end--;

                while (start < n && arr[start] == arr[start - 1])
                {
                    start++;
                }

                while (end > i && arr[end] == arr[end + 1])
                {
                    end--;
                }
            }

            else if (sum > K)
            {
                end--;
            }

            else
            {
                start++;
            }
        }

        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;
    }

    return triplets;
}