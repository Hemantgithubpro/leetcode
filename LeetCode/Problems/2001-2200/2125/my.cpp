#include <bits/stdc++.h>
using namespace std;

// did in first try, but not the most optimal soln

int no(string &s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    return cnt;
}
int cntbwtwos(string &s1, string &s2)
{
    int a = no(s1), b = no(s2);
    return a * b;
}
int numberOfBeams(vector<string> &bank)
{
    int ans = 0;
    for (int i = 0; i < bank.size() - 1; i++)
    {
        for (int j = i + 1; j < bank.size(); j++)
        {
            if (cntbwtwos(bank[i], bank[j]))
            {
                ans += cntbwtwos(bank[i], bank[j]);
                break;
            }
        }
        // if (no(bank[i]) > 0)
        // {
        //     int temp = i + 1;
        // while (no(bank[temp]) == 0 && temp < bank.size())
        //     temp++;
        // if (temp == bank.size())
        //     continue;
        //     if (no(bank[temp]) > 0)
        //         ans += cntbwtwos(bank[i], bank[temp]);
        // }
    }
    return ans;
}

int main()
{
    vector<string> bank = {"000", "111", "000"};
    cout << numberOfBeams(bank);
    return 0;
}