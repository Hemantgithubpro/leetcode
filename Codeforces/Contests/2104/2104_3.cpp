#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &a)
{
    return (a[0] == a[1] && a[1] == a[2]);
}

string solve(vector<int> &a)
{
    int x = a[0], y = a[1], z = a[2];  // x < y < z
    
    // For each possible final count k where k >= max(x,y)
    for (int k = max(x,y); k <= z; k++) {
        // Calculate how many cards we need to move from z
        int need_x = k - x;  // cards needed for first deck
        int need_y = k - y;  // cards needed for second deck
        int total_needed = need_x + need_y;  // total cards we need to move
        
        // Check if we can take these many cards from z while keeping z equal to k
        if (total_needed >= 0 && total_needed <= z - k) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        vector<int> a(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        cout << solve(a) << endl;
    }
}
