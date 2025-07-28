#include <bits/stdc++.h>
using namespace std;

int largestCombination(vector<int> &c)
{
    // vector<int> count(32, 0);
    // count[i]=how many no. have ith bit set

    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int countI=0;
        for (int &num : c)
        {
            if (num & (1 << i))
                // count[i]++;
                countI++;
        }

        // result = max(result, count[i]);
        result = max(result, countI);
    }
    return result;
    // array<int,43> a={}; // new way of declaring array
}

int main()
{
    vector<int> candidates = {33, 93, 31, 99, 74, 37, 3, 4, 2, 94, 77, 10, 75, 54, 24, 95, 65, 100, 41, 82, 35, 65, 38, 49, 85, 72, 67, 21, 20, 31};
    cout << largestCombination(candidates);
}