#include <bits/stdc++.h>
int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    // unordered_map<int,int>mp;
    // for(auto it:arr)
    // mp[it]++;

    // for(auto it:mp)
    //  if(it.second==1)
    //   return it.first;

    // return -1;

    // if we are at even index then index^1=next index and at odd index then index^1=previous index
    int start = 0;
    int end = arr.size() - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == arr[mid ^ 1])
            start = mid + 1;

        else
            end = mid - 1;
    }

    return arr[start];
}