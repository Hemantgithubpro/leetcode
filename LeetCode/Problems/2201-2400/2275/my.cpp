#include <bits/stdc++.h>
using namespace std;

int sizeofmaxi(vector<int> &c, int idx, int andval, int size)
{
    if (idx == c.size())
        return (andval > 0) ? size : 0;
    // Take current element
    int take = sizeofmaxi(c, idx + 1, (size == 0 ? c[idx] : (andval & c[idx])), size + 1);
    // Don't take current element
    int skip = sizeofmaxi(c, idx + 1, andval, size);
    return max(take, skip);
}

int largestCombination(vector<int> &c)
{
    // either take it or leave it: 2^n, first try with this approach
    int maxi = 0;
    maxi = sizeofmaxi(c, 0, 0, 0);
    return maxi;
}

int main()
{
    vector<int> candidates = {33, 93, 31, 99, 74, 37, 3, 4, 2, 94, 77, 10, 75, 54, 24, 95, 65, 100, 41, 82, 35, 65, 38, 49, 85, 72, 67, 21, 20, 31};
    cout << largestCombination(candidates);
}