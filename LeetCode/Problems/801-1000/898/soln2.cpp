#include <bits/stdc++.h>
using namespace std;

int subarrayBitwiseORs(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        us.insert(arr[i]);
        for (int j = i - 1; j >= 0; j--)
        {
            if ((arr[i] | arr[j]) == arr[j])
                break;
            arr[j] |= arr[i];
            us.insert(arr[j]);
        }
    }
    return us.size();
}