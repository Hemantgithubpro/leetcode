#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    if (num.size() < 3)
        return "";

    int maxi = -1;
    for (int i = 0; i < num.size() - 2; i++)
    {
        char temp = num[i];
        if (num[i + 1] == temp && num[i + 2] == temp)
        {
            string t = "";
            t.append(3, temp);
            int a = stoi(t);
            if (a > maxi)
                maxi = a;
        }
    }
    if (maxi < 0)
        return "";
    string ans = to_string(maxi);
    if (maxi == 0)
        return "000";
    return ans;
}

int main()
{
}