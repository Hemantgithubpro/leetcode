#include <bits/stdc++.h>
using namespace std;
int totalMoney(int n)
{
    // 1 2 3 ... 7 2 3 4 ... 8 ... repeat
    int ans = 0;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i - 1) % 7 == 0)
            count++;
        ans += count + ((i - 1) % 7);
    }
    return ans;
}

int main()
{
    int n = 20;
    cout << totalMoney(n);
}