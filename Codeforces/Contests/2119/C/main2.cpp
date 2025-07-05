/*
 * SOLUTION FOR PROBLEM 1: Euclidean Path
 *
 * This program determines if a target point is reachable from a starting point
 * after a series of moves with specified lengths.
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// Use long long for coordinates and distances to avoid overflow with large values.
using ll = long long;

void solve_euclidean_path()
{
    int n;
    std::cin >> n;
    ll px, py, qx, qy;
    std::cin >> px >> py >> qx >> qy;

    std::vector<ll> a(n);
    ll sum_a = 0;
    ll max_a = 0;

    // Read move lengths, calculate their sum and find the maximum move.
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        sum_a += a[i];
        if (a[i] > max_a)
        {
            max_a = a[i];
        }
    }

    // Calculate the squared Euclidean distance between start and end points.
    // We use squared distances to avoid floating-point inaccuracies and work with integers.
    ll dx = px - qx;
    ll dy = py - qy;
    ll target_dist_sq = dx * dx + dy * dy;

    // The maximum possible distance we can be from the start is the sum of all move lengths.
    ll max_reach = sum_a;

    // The minimum possible distance is determined by the longest move vs. the sum of all others.
    // If the longest move is shorter than the sum of the rest, we can arrange the moves
    // to return to the origin (or very close), so the minimum distance is 0.
    // Otherwise, the minimum distance is the longest move minus the sum of the rest.
    ll sum_others = sum_a - max_a;
    ll min_reach = 0;
    if (max_a > sum_others)
    {
        min_reach = max_a - sum_others;
    }

    // Square the min and max reachable distances for comparison.
    ll min_reach_sq = min_reach * min_reach;
    ll max_reach_sq = max_reach * max_reach;

    // The target is reachable if and only if its distance from the start
    // is within the range [min_reach, max_reach].
    if (min_reach_sq <= target_dist_sq && target_dist_sq <= max_reach_sq)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}

/*
 * SOLUTION FOR PROBLEM 2: Bitwise AND and XOR
 *
 * This program finds the k-th element of the lexicographically smallest
 * array `a` where all elements are in [l, r] and the bitwise AND of
 * all elements equals their bitwise XOR.
 */
#include <iostream>
#include <cmath>

// On Windows with MSVC, you might need <intrin.h> for __lzcnt64
#if defined(_MSC_VER)
#include <intrin.h>
#endif

// Use long long for n, l, r, k as they can be very large.
using ll = long long;

// Helper function to get the position of the most significant bit (0-indexed).
// Using compiler built-ins is much faster than a manual loop or log2.
ll get_msb_pos(ll n)
{
    if (n == 0)
        return -1; // No bits are set
#if defined(__GNUC__) || defined(__clang__)
    // __builtin_clzll counts leading zeros for a 64-bit long long.
    return 63 - __builtin_clzll(n);
#elif defined(_MSC_VER)
    unsigned long index;
    _BitScanReverse64(&index, n);
    return index;
#else
    // A fallback for other compilers.
    ll pos = 0;
    while ((1LL << (pos + 1)) <= n && (pos + 1) < 63)
    {
        pos++;
    }
    return pos;
#endif
}

void solve_bitwise_array()
{
    ll n, l, r, k;
    std::cin >> n >> l >> r >> k;

    // Case 1: n is odd.
    // The simplest solution is an array where all elements are 'l'.
    // The AND of 'n' identical numbers is the number itself.
    // The XOR of an odd number of identical numbers is also the number itself.
    // So, [l, l, ..., l] is a valid array, and it's lexicographically smallest.
    if (n % 2 != 0)
    {
        std::cout << l << "\n";
        return;
    }

    // Case 2: n is even.

    // Subcase 2a: n = 2.
    // The condition a1&a2 = a1^a2 can only be satisfied if a1=a2=0,
    // which is impossible since l, r are positive.
    if (n == 2)
    {
        std::cout << -1 << "\n";
        return;
    }

    // Subcase 2b: n is even and n > 2.
    // A simple structure that makes the total XOR zero is pairs of identical numbers.
    // To make the total AND zero, we need at least one pair of numbers (z1, z2)
    // in our array construction such that z1 & z2 = 0.
    // The lexicographically smallest array will be of the form [l, l, ..., l, z2, z2].
    // This requires finding a z2 in [l, r] such that l & z2 = 0.

    // This is only possible if l and r do not share the same most significant bit.
    // If they do, all numbers in [l, r] have that bit set, so their AND can't be 0.
    ll msb_l_pos = get_msb_pos(l);
    ll msb_r_pos = get_msb_pos(r);

    if (msb_l_pos != msb_r_pos)
    {
        // A solution exists. The first element is z1 = l.
        // The second element, z2, can be the smallest power of 2 strictly greater than l.
        // This z2 is guaranteed to be <= r if msb(l) != msb(r).
        ll z1 = l;
        ll z2 = 1LL << (msb_l_pos + 1);

        // The array is composed of n-2 copies of z1 and 2 copies of z2.
        // Since z1=l and z2>l, the lexicographically smallest arrangement is
        // [z1, z1, ..., z1, z2, z2].
        // The problem uses 1-based indexing for k.
        if (k <= n - 2)
        {
            std::cout << z1 << "\n";
        }
        else
        {
            std::cout << z2 << "\n";
        }
    }
    else
    {
        // No solution exists if all numbers in the range share an MSB.
        std::cout << -1 << "\n";
    }
}

// You can switch between the two solutions by changing the function call in main.
int main()
{
    // Fast I/O

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        // Call the solver for the desired problem.
        solve_euclidean_path();
        // solve_bitwise_array();
    }

    return 0;
}
