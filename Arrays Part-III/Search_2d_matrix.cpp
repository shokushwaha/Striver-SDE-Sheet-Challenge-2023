bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int i = 0;
    int j = n * m - 1;
    int mid = (i + j) / 2;
    while (i <= j)
    {
        int row = mid / n;
        int col = mid % n;

        if (mat[row][col] == target)
            return true;

        else if (mat[row][col] > target)
            j = mid - 1;

        else
            i = mid + 1;

        mid = (i + j) / 2;
    }

    return false;
}