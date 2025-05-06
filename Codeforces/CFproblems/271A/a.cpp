#include <bits/stdc++.h>
using namespace std;

bool isalldiff(int n){
    unordered_set<int> s;
    for(int i=0; i<4; i++){
        s.insert(n%10);
        n/=10;
    }
    return s.size()==4;
}

void solve(int t){
    t++;
    while(t<9013){
        if(isalldiff(t)){
            cout << t << endl;
            return;
        }
        t++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    solve(t);

    return 0;
}
