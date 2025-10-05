#include <bits/stdc++.h>
using namespace std;

// this is my approach after watching half of the soln, but i missedsomething.
void solve()
{
    // code
    int a, b;
    cin >> a >> b;
    // a in one direc and b in other

    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    // coordinated of king and queen

    // positions of knight which can attack king
    // vector<pair<int, int>> king; // pair<int,int> king= (x1,y1) ...
    // instead of vector of pair i'll use set of pairs
    set<pair<int,int>> king;
    
    king.insert({xk + a, yk + b});
    king.insert({xk + a, yk - b});
    king.insert({xk - a, yk + b});
    king.insert({xk - a, yk - b});
    king.insert({xk + b, yk + a});
    king.insert({xk + b, yk - a});
    king.insert({xk - b, yk + a});
    king.insert({xk - b, yk - a});
    
    // vector<pair<int, int>> queen; // pair<int,int> king= (x1,y1) ...
    set<pair<int,int>> queen;
    queen.insert({xq + a, yq + b});
    queen.insert({xq + a, yq - b});
    queen.insert({xq - a, yq + b});
    queen.insert({xq - a, yq - b});
    queen.insert({xq + b, yq + a});
    queen.insert({xq + b, yq - a});
    queen.insert({xq - b, yq + a});
    queen.insert({xq - b, yq - a});

    int ans=0;
    for(auto position: king){
        if(queen.find(position) != queen.end()) ans++;
    }
    
    // a more better soln is written in soln2.cpp
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
        solve();
    }

    return 0;
}
