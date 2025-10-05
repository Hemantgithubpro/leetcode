#include <bits/stdc++.h>
using namespace std;

// i know this is not the intended way, but it did works. and who cares.
// void sortColors(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
// }

// proper solution
void sortColors(vector<int> &nums)
{
    unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};

    for (int num : nums)
    {
        count[num]++;
    }

    int idx = 0;
    for (int color = 0; color < 3; color++)
    {
        int freq = count[color];
        for (int j = 0; j < freq; j++)
        {
            nums[idx] = color;
            idx++;
        }
    }
}

int main()
{
}