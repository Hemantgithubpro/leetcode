#include <bits/stdc++.h>
using namespace std;

void solve(int a,int b, int c , int d){

    // if k is odd && g's knight is alive
    // first turn is g's knight and alternatively
    // if k is even && f's knight is alive

    // approach
    // 1. if 

    int temp1=min(a,b);
    int temp2=max(a,b);

    int temp3=min(c,d);
    int temp4=max(c,d);
    
    // if(d<b){    // knight will be attacked first
        
    // }
    // else{   // f will be attacked first 

    // }

    if(a+b >= c+d){
        
    }
    else{

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
    while (t--) {
        // input
        int a,b,c,d;
        cin>>a; // HP of Gellyfish
        cin>>b; //       Flower
        cin>>c; //       Gellyfish's knight
        cin>>d; //       Flower's knight
        solve(a,b,c,d);
    }

    return 0;
}
