#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
    vector<vector<int>> result;
    vector<int> t = {1};
    result.push_back(t);
    if (n < 2)
        return result;
    result.push_back({1, 1});
    if (n == 2)
        return result;
    // base cases are done

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp(i, 1);
        for (int j = 1; j < i - 2; j++)
        {
            
        }
    }
}

int main()
{
}