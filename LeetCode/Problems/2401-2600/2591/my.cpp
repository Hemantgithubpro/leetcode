#include <bits/stdc++.h>
using namespace std;

bool checkif4(vector<int> &c)
{
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == 4)
            return true;
    }
    return false;
}

int distMoney(int money, int children)
{
    if (money < children)
        return -1;

    money -= children;
    vector<int> c(children, 1);
    int ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        if (money >= 7)
        {
            money -= 7;
            c[i] += 7;
            ans++;
        }
        else
        {
            c[i] += money;
            money = 0;
            break;
        }
    }
    if (money)
        ans--;
    if (checkif4(c))
    {
        int n = c.size();
        if (c[n - 1] == 4)
            ans--;
    }
    return ans;
}

int main()
{
    int m = 20, c = 3;
    cout << distMoney(m, c);
}