#include <bits/stdc++.h>
using namespace std;
// actually i understood the question wrong.
// the concept is totally different, if there are three consecutive empty cells, then you can create unlimited water cells.

bool ifallfull(vector<char> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            return false;
    }
    return true;
}

bool ifallempty(vector<char> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
            return false;
    }
    return true;
}

bool if3consempt(vector<char>&s){
    for (int i = 2; i < s.size(); i++)
    {
        if(s[i]=='.'&&s[i-1]=='.'&&s[i-2]=='.') return true;
    }
    return false;
    
}

void solve(int n, vector<char> &s)
{
    int ans = 0;
    if (ifallfull(s))
    {
        cout << 0 << endl;
        return;
    }

    if(if3consempt(s)){
        cout<<2<<endl;
        return;
    }
    else{
        int noofempty=0;
        for (int i = 0; i < n;i++)
        {
            if(s[i]=='.') ans++;
        }
    }
    

    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        int n;
        cin >> n;
        vector<char> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        solve(n, s);
    }

    return 0;
}
