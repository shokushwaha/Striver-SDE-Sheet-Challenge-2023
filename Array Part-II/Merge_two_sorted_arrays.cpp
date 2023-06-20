vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int left = m - 1;
    int right = 0;

    while (left >= 0 && right < n)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
            break;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (auto it : arr2)
        arr1.push_back(it);
}