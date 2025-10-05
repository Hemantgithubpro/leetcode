#include <bits/stdc++.h>
using namespace std;
string rle(string a)
{
    string ans = "";
    for (int i = 0; i < a.size(); i++)
    {
        int count = 1;
        while (i + 1 < a.size() && a[i] == a[i + 1])
        {
            count++;
            i++;
        }
        ans += to_string(count) + a[i];
    }
    return ans;
}

string countAndSay(int n)
{
    // recursion will be there
    if(n==1) return "1";
    return rle(countAndSay(n-1));
}

int main()
{
    int n = 4; // Change to test different values
    cout << countAndSay(n) << endl; // Uncomment to see the result
    // cout<<rle("21");
    return 0;
}

