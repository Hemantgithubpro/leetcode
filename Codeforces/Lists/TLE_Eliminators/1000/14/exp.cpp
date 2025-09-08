#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    vector<int> ab(n);
    iota(ab.begin(), ab.end(), 1);

    for (int i = 0; i < n; i++)
    {
        cout << ab[i] << ' ';
    }
    return 0;
}