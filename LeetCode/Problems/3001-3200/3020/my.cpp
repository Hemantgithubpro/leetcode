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

    unordered_map<int, int> um;
    for (int a : nums)
        um[a]++;

    ans = max(ans, countones(nums));

    int maxi = *max_element(nums.begin(), nums.end());

    for (int i = 2; i * i <= maxi; i++)
    {

        int freq = 0;
        for (int j = i; j * j <= maxi; j = j * j)
        {
            if (um[j] >= 2)
                freq += 2;
            else if (um[j] == 1)
            {
                freq++;
                ans = max(freq, ans);
                break;
            }
            else
                break;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums={5,4,1,1,2,2};

    cout<<endl<<maximumLength(nums);

    return 0;

}