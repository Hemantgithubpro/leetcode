#include <bits/stdc++.h>
using namespace std;

int countones(vector<int> &nums)
{
    int cnt = 0;
    for (int n : nums)
        if (n == 1)
            cnt++;
    return cnt;
}
int maximumLength(vector<int> &nums)
{
    int ans = 1;
    // assume the array is of size n, n has to be odd
    // only x is variable, otherwise all other elements are known
    // freq of x is 2, x^2 is 2, ... x^2p is 1

    unordered_map<long long, long long> um;
    for (long long a : nums)
        um[a]++;

    ans = max(ans, countones(nums));

    int maxi = *max_element(nums.begin(), nums.end());

    for (long long i = 2; i * i <= maxi; i++)
    {
        // cout<<"i: "<<i<<' ';
        int freq = 0;
        long long lastvalid = -1;
        for (long long j = i; j * j <= maxi; j = j * j)
        {
            // cout << "j: " << j << ' ';
            if (um[j] >= 2)
            {
                freq += 2;
                lastvalid = j;
            }
            else
                break;
            // cout << endl;
        }
        if (um[lastvalid * lastvalid] > 0)
        {
            freq++;
        }
        ans = max(freq, ans);
        // cout<<endl;
    }
    if (!(ans % 2))
        ans--;
    return ans;
}

int main()
{
    vector<int> nums = {5, 4, 1, 1, 2, 2};

    cout << endl
         << maximumLength(nums);

    return 0;
}