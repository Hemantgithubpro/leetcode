// recursive one
#include <bits/stdc++.h>
using namespace std;

// double f(int a, int b)
// {
//     if (a <= 0 && b > 0)
//         return 1.0; // A finishes first
//     if (a <= 0 && b <= 0)
//         return 0.5; // Both finish together
//     if (a > 0 && b <= 0)
//         return 0.0; // B finishes first

//     return 0.25 * (f(a - 100, b) +
//                    f(a - 75, b - 25) +
//                    f(a - 50, b - 50) +
//                    f(a - 25, b - 75));
// }
// double soupServings(int n)
// {
//     if (n > 4800)
//         return 1.0; // Optimization: result converges to 1 as n grows
//     return f(n, n);
// }

unordered_map<int, unordered_map<int, double>> memo;

double dfs(int a, int b)
{
    if (a <= 0 && b > 0)
        return 1.0;
    if (a <= 0 && b <= 0)
        return 0.5;
    if (a > 0 && b <= 0)
        return 0.0;

    if (memo[a][b] > 0)
        return memo[a][b];

    memo[a][b] = 0.25 * (dfs(a - 100, b) +
                         dfs(a - 75, b - 25) +
                         dfs(a - 50, b - 50) +
                         dfs(a - 25, b - 75));

    return memo[a][b];
}
double soupServings(int n)
{
    if (n > 4800)
        return 1.0; // To avoid TLE for large n
    return dfs(n, n);
}

int main()
{
    int n = 100;
    cout << soupServings(n) << endl;
    return 0;
}