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
    
    // For Gellyfish strategy:
    // 1. Attack Flower directly
    int g_direct_attack = g_turns_to_kill_f;
    
    // 2. Kill Flower's knight first, then attack Flower
    // Need to account for alternating turns - Flower attacks on even turns
    int g_kill_knight_first = g_turns_to_kill_knight;
    // After knight is dead, Gellyfish needs (b + c - 1) / c turns to kill Flower
    int g_after_knight = (b + c - 1) / c;
    int g_strategy2 = g_kill_knight_first + g_after_knight;
    
    // For Flower strategy:
    // 1. Attack Gellyfish directly
    int f_direct_attack = f_turns_to_kill_g;
    
    // 2. Kill Gellyfish's knight first, then attack Gellyfish
    int f_kill_knight_first = f_turns_to_kill_knight;
    // After knight is dead, Flower needs (a + d - 1) / d turns to kill Gellyfish
    int f_after_knight = (a + d - 1) / d;
    int f_strategy2 = f_kill_knight_first + f_after_knight;
    
    // Best strategy for each player
    int g_best = min(g_direct_attack, g_strategy2);
    int f_best = min(f_direct_attack, f_strategy2);
    
    // Gellyfish goes first (odd turns), so we need to adjust the comparison
    // Gellyfish needs to win in <= turns than Flower
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
