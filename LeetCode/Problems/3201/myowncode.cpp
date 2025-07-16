#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int> &nums)
{
    int maxi = INT_MIN;
    // all odd or all even
    vector<int> allodd, alleven;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2)
            allodd.push_back(nums[i]);
        else
            alleven.push_back(nums[i]);
    }
    if (max(allodd.size(), alleven.size()) == nums.size())
        return nums.size();
    maxi = max(maxi, static_cast<int>(allodd.size()));
    maxi = max(maxi, static_cast<int>(alleven.size()));

    // alternate odd even, odd first
    vector<int> altodd;
    int j = 0;
    while (nums[j] % 2 != 1)
        j++;
    altodd.push_back(nums[j]);
    bool odd = true;
    // now jth element if first odd element.
    for (int i = j; i < nums.size(); i++)
    {
        if (odd)
        { // need to find next even number
            if (nums[i] % 2 == 0)
            {
                altodd.push_back(nums[i]);
                odd = !odd;
            }
        }
        else
        { // need to find next odd number
            if (nums[i] % 2)
            {
                altodd.push_back(nums[i]);
                odd = !odd;
            }
        }
    }
    maxi = max(maxi, static_cast<int>(altodd.size()));

    // alternate odd even, even first
    vector<int> alteven;
    int j = 0;
    while (nums[j] % 2 != 0)
        j++;
    alteven.push_back(nums[j]);
    bool even = true;
    // now jth element if first even element.
    for (int i = j; i < nums.size(); i++)
    {
        if (even)
        { // need to find next odd number
            if (nums[i] % 2)
            {
                alteven.push_back(nums[i]);
                even = !even;
            }
        }
        else
        { // need to find next even number
            if (nums[i] % 2 == 0)
            {
                alteven.push_back(nums[i]);
                even = !even;
            }
        }
    }
    maxi = max(maxi, static_cast<int>(alteven.size()));

    return maxi;
}

int main()
{
}