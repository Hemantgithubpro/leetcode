#include <bits/stdc++.h>
using namespace std;
// one of the easiest questions, you just have to dry run it in notes.md or any txt file
void solve(int n)
{
    // code
    // three cases if n%3==0,1,2
    if(n%3==0) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
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

        solve(n);
    }

    return 0;
}
