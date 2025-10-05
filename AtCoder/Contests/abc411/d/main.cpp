#include <bits/stdc++.h>
using namespace std;

// string a="sdf";
// string b="kjl";
// string c=a+b;
// cout<<c;

int main()
{
    // 1 p: Replace the string of PC p with the string of the server.
    // 2 p s: Append string s to the end of the string of PC p.
    // 3 p: Replace the string of the server with the string of PC p.

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    string server = "";
    vector<string> pc(n, "");

    while (q--)
    {
        string a;
        cin>>a;
        if(a[0]=='1'){
            string temp;
        }
        else if(a[0]=='2'){

        }
        else{

        }
    }
    return 0;
}
