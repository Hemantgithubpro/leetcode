#include <bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    int ans = numBottles;
    int full = 0;
    int empty = numBottles;
    full = empty / numExchange;
    empty %= numExchange;
    while (full > 0)
    {
        ans += full;
        empty += full;
        full = empty / numExchange;
        empty %= numExchange;
    }
    return ans;
}

int main()
{
}