#include <bits/stdc++.h>
using namespace std;

// correct but gave tle
int subarrayBitwiseORs(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i; j < n; j++)
        {
            temp |= arr[j];
            us.insert(temp);
        }
    }
    return us.size();
}

int main()
{
}