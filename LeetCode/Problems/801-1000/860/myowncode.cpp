#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    unordered_map<int, int> um;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            um[5]++;
        }
        else if (bills[i] == 10)
        {
            // five--, ten++
            if (um[5] >= 1)
            {
                um[5]--;
                um[10]++;
            }
            else
                return false;
        }
        else
        {
            if (um[10] >= 1 && um[5] >= 1)
            {
                um[5]--;
                um[10]--;
            }
            else if (um[5] >= 3)
            {
                um[5] -= 3;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
}
