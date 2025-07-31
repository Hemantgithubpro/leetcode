#include <bits/stdc++.h>
using namespace std;

// soln
int subarrayBitwiseORs(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> us;
    unordered_set<int> prev;
    unordered_set<int> curr;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        for (const int &x : prev)
        {
            curr.insert(x|arr[i]);
            us.insert(x|arr[i]);
        }

        curr.insert(arr[i]);
        us.insert(arr[i]);

        prev = curr;
        curr.clear();
    }
    return us.size();
}

int main()
{
}