// I thought it would give me TLE, but it passed with 100%ile in time complexity.
// But I still guess, there could be a more optimal solution wrt TC.

bool isdivisible(long long m, int k)
{
    if (m % k == 0)
        return true;
    return false;
}

int countPairs(vector<int> &nums, int k)
{
    // for i*j to be divisible by k, i*j=m, m%k=0, m=0,k,2k,3k...
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                if (isdivisible(i * j, k))
                    ans++;
            }
        }
    }

    return ans;
}