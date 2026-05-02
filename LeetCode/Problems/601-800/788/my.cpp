#include <bits/stdc++.h>
using namespace std;

bool isgood(int n, unordered_map<int, int> &um)
{
    int orgnum = n;
    int newnum = 0;
    while (n)
    {
        int temp = n % 10;
        if (um[temp])
        {
            newnum += temp;
            newnum *= 10;
        }
        else
            return false;
        n = n / 10;
    }
    // reverse newnum
    int nnum = 0;
    while (newnum)
    {
        int t = newnum % 10;
        nnum += t;
        nnum *= 10;

        newnum /= 10;
    }
    if (nnum == orgnum)
        return false;
    return true;
}

int rotatedDigits(int n)
{
    // mapping or dictionary
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

    if(memo[n]) 
    
    return 0;
}

int main()
{
    int n = 4;
    rotatedDigits(n);
}