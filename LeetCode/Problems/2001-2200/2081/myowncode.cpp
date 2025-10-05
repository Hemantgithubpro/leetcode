// TLE
// this potd is hard, but let's try.
#include <bits/stdc++.h>
using namespace std;

string tokbase(int a, int k)
{
    // you divide it by 'k', take the remainder and append it to answer.
    string ans = "";
    while (a > 0)
    {
        string temp;
        int rem = a % k;
        a = a / k;
        temp = to_string(rem);
        ans += temp;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool iskmirror(int n, int k)
{
    string s = to_string(n);
    string temps = s;
    reverse(temps.begin(), temps.end());
    if (s != temps)
        return false;
    string d = tokbase(n, k);
    string d2 = d;
    reverse(d2.begin(), d2.end());
    if (d != d2)
        return false;
    return true;
}

long long kMirror(int k, int n)
{
    // sum of the 'n' smallest k-mirrored numbers
    // brute force soln
    long long ans=0;
    int count=1;
    for(int i=1; count<=n; i++){
        if(iskmirror(i,k)){
            ans+=i;
            count++;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int k = 2;
    // cout << iskmirror(k, n);
    cout<<kMirror(k,n);
}