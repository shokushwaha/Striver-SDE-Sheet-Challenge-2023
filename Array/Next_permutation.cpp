#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> nextPer = permutation;

    int i = n - 2, j;

    while (i >= 0 && nextPer[i + 1] < nextPer[i])
    {
        i--;
    }

    if (i < 0)
    {
        reverse(nextPer.begin(), nextPer.end());
    }

    else
    {
        j = n - 1;
        while (j >= 0 && nextPer[i] > nextPer[j])
        {
            j--;
        }
        swap(nextPer[i], nextPer[j]);
        reverse(nextPer.begin() + i + 1, nextPer.end());
    }

    return nextPer;
}