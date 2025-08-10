#include <bits/stdc++.h>
using namespace std;
// solution was correct on first try, but a more optimized solution is there
// all permutations is valid for the given constraints, under 9! which is under 10^8
// another method, store all powers of two, in a hash map
bool reorderedPowerOf2(int n)
{
    unordered_map<int, int> um;
    while (n > 0)
    {
        int temp = n % 10;
        um[temp]++;
        n = n / 10;
    }

    vector<unordered_map<int, int>> um2;
    int t = 1;
    for (int i = 0; i < 30; i++)
    {
        int a = t;
        unordered_map<int, int> umt;
        while (a > 0)
        {
            int temp = a % 10;
            umt[temp]++;
            a = a / 10;
        }
        t *= 2;
        um2.push_back(umt);
    }

    for (int i = 0; i < um2.size(); i++)
    {
        if (um2[i] == um)
            return true;
    }
    return false;
}

int main()
{
}