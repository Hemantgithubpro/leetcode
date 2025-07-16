#include <bits/stdc++.h>
using namespace std;

// this function gave tle, so i'll use dp with memoization
// int climbStairs(int n)
// {
//     if (n == 1)
//         return 1;
//     if (n == 2)
//         return 2;
//     return (climbStairs(n - 1) + climbStairs(n - 2));
// }

// dp with memoization
// this vector outside the function is causing problems in leetcode
// vector<int> memo(46,-1);
// int climbStairs(int n){
//     if(memo[n]!=-1) return memo[n];
//     if(n==1) return 1;
//     if(n==2) return 2;
//     memo[n] = climbStairs(n-1) + climbStairs(n-2);
//     return memo[n];
// }

// now this funcn was taken from solution
int climbStairs(int n)
{
    if (n <= 3)
        return n;

    int prev1 = 3;
    int prev2 = 2;
    int cur = 0;

    for (int i = 3; i < n; i++)
    {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    return cur;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int n = 44;
    cout << climbStairs(n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "\nTime taken: " << duration.count() << " milliseconds";
}