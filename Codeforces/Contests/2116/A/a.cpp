#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c, int d) {
    // Gellyfish goes first (k is odd initially)
    
    if (c <= 0) {
        // Only Gellyfish's knight is dead
        // Flower's knight will attack and win
        cout << "Flower" << endl;
        return;
    }
    
    if (d <= 0) {
        // Only Flower's knight is dead
        // Gellyfish's knight will attack and win
        cout << "Gellyfish" << endl;
        return;
    }
    
    // Both knights are alive
    // Calculate how many turns it takes for each knight to defeat the opponent
    
    // Turns needed for Gellyfish's knight to kill Flower's HP
    int g_turns_to_kill_f = (b + c - 1) / c;
    
    // Turns needed for Flower's knight to kill Gellyfish's HP
    int f_turns_to_kill_g = (a + d - 1) / d;
    
    // Turns needed for Gellyfish's knight to kill Flower's knight
    int g_turns_to_kill_knight = (d + c - 1) / c;
    
    // Turns needed for Flower's knight to kill Gellyfish's knight
    int f_turns_to_kill_knight = (c + d - 1) / d;
    
    // Priority 1: Kill opponent directly unless knight has low HP
    
    // For Gellyfish:
    int g_best;
    // If Flower's knight has low HP (efficient to kill first)
    if (d < b) {
        // Kill knight first, then attack Flower
        g_best = g_turns_to_kill_knight + (b + c - 1) / c;
    } else {
        // Attack Flower directly
        g_best = g_turns_to_kill_f;
    }
    
    // For Flower:
    int f_best;
    // If Gellyfish's knight has low HP (efficient to kill first)
    if (c < a) {
        // Kill knight first, then attack Gellyfish
        f_best = f_turns_to_kill_knight + (a + d - 1) / d;
    } else {
        // Attack Gellyfish directly
        f_best = f_turns_to_kill_g;
    }
    
    // Gellyfish goes first (odd turns)
    if (g_best <= f_best) {
        cout << "Gellyfish" << endl;
    } else {
        cout << "Flower" << endl;
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
