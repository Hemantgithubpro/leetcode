#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    x--; // Convert to 0-indexed

    // Check if Hamid can escape immediately in either direction
    bool canEscapeLeft = true, canEscapeRight = true;

    // Check for walls to the left
    for (int i = 0; i < x; i++)
    {
        if (s[i] == '#')
        {
            canEscapeLeft = false;
            break;
        }
    }

    // Check for walls to the right
    for (int i = x + 1; i < n; i++)
    {
        if (s[i] == '#')
        {
            canEscapeRight = false;
            break;
        }
    }

    // If Hamid can escape immediately in either direction, answer is 1
    if (canEscapeLeft || canEscapeRight)
    {
        cout << 1 << "\n";
        return;
    }

    // If there are walls on both sides, find the nearest wall in each direction
    int leftWall = -1, rightWall = n;

    // Find nearest wall to the left
    for (int i = x - 1; i >= 0; i--)
    {
        if (s[i] == '#')
        {
            leftWall = i;
            break;
        }
    }

    // Find nearest wall to the right
    for (int i = x + 1; i < n; i++)
    {
        if (s[i] == '#')
        {
            rightWall = i;
            break;
        }
    }

    // Calculate steps to reach the nearest wall in each direction
    int leftSteps = (leftWall == -1) ? x + 1 : x - leftWall;
    int rightSteps = (rightWall == n) ? n - x : rightWall - x;

    // Count empty cells on each side (excluding Hamid's current position)
    int leftEmpty = 0, rightEmpty = 0;
    for (int i = 0; i < x; i++)
    {
        if (s[i] == '.')
            leftEmpty++;
    }
    for (int i = x + 1; i < n; i++)
    {
        if (s[i] == '.')
            rightEmpty++;
    }

    // Hamid chooses the direction with fewer steps
    // Mani will place walls to maximize the minimum escape time
    // The answer is the distance to the nearest wall, as Hamid will head there
    // and Mani can't effectively block more than that due to Hamid's choice
    int days = max(min(leftSteps, rightSteps), 1);

    // Adjust for Mani's ability to place walls in remaining empty cells
    // However, since Hamid moves after Mani places a wall each day,
    // and Hamid can choose direction, the minimum steps to a wall or edge
    // considering Mani's wall placement each day simplifies to initial min distance
    cout << min(leftSteps, rightSteps) << "\n";
}

// void solve(ll n, vector<ll>& a){

// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
