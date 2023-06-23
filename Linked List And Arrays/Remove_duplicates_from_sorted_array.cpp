int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (arr[i] == arr[j])
            j++;
        else if (arr[i] != arr[j])
        {
            swap(arr[i + 1], arr[j]);
            i++;
            j++;
        }
    }
    return i + 1;
}