#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int> &nums)
{
    int cnt = 0;
    for (int n : nums)
        if (n % 3)
            cnt++;
    return cnt;
}

int main()
{
}