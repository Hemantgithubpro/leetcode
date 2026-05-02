#include <bits/stdc++.h>
using namespace std;

bool isgood(int n, unordered_map<int, int> &um)
{
    int orgnum = n;
    int newnum = 0;
    int multiplier = 1;
    while (n)
    {
        int temp = n % 10;
        if (um[temp] != -1)
        {
            newnum = newnum + um[temp] * multiplier;
            multiplier *= 10;
        }
        else
            return false;
        n = n / 10;
    }
    
    if (newnum == orgnum)
        return false;
    return true;
}

int solveRec(int n, unordered_map<int, int> &um, vector<int>& memo) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    
    return memo[n] = solveRec(n - 1, um, memo) + (isgood(n, um) ? 1 : 0);
}

int rotatedDigits(int n)
{
    vector<int> memo(n + 1,-1);

    unordered_map<int, int> um;
    um[0] = 0;
    um[1] = 1;
    um[2] = 5;
    um[3] = -1;
    um[4] = -1;
    um[5] = 2;
    um[6] = 9;
    um[7] = -1;
    um[8] = 8;
    um[9] = 6;

    return solveRec(n, um, memo);
}

int main()
{
    int n = 10;
    cout<<rotatedDigits(n);

    return 0;
}