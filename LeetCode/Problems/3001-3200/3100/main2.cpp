#include <bits/stdc++.h>
using namespace std;

int exchange(int &empty, int &ne)
{
    int ans = 0;
    while (empty >= ne)
    {
        empty -= ne;
        ans++;
        ne++;
    }
    return ans;
}
int maxBottlesDrunk(int numBottles, int numExchange)
{
    // greedy ki tarah hi hona chahiye
    int ans = 0;
    int empty = 0;
    int full = numBottles;
    int ne = numExchange;

    while (full)
    {
        ans += full;
        empty += full;
        full = 0;
        full += exchange(empty, ne);
        // empty%=ne;
        // ne++;
        // cout <<ne<<" "<< full<<endl;
    }
    return ans;
}

int main()
{
    int nb = 10;
    int ne = 3;
    cout << maxBottlesDrunk(nb, ne);
}