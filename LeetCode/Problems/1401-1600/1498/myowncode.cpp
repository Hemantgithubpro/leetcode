#include <bits/stdc++.h>
using namespace std;

bool isless(int al, int ar, int target)
{
    return (al + ar) <= target;
}

// i don't know how to handle duplicates, it has made things complicated.
int numSubseq(vector<int> &nums, int target)
{
    const long long MOD = 1e9 + 7;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long ans = 0;

    // two pointers
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        cout << "i: " << i << " " << "j: " << j;
        if (isless(nums[i], nums[j], target))
        {
            cout << " yes";
            if (i == j)
                ans++;
            else
                // ans += abs(j - i + 1);
                ans+=pow(2,j-i);
            j++;
        }
        else
            i++;
        cout << endl;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 6, 8};
    int target = 10;
    cout << numSubseq(nums, target);
}