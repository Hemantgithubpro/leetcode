#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &nums, int k)
{
    int n= nums.size();
    vector<long long> prefixSum(n,nums[0]);
    for(int i=1; i<n; i++){
        prefixSum[i]=nums[i]+prefixSum[i-1];
    }

    long long sum=LLONG_MIN;
    // size of k,2k,3k ... is allowed then prefix sum
    while(k<n){
        // sliding window of k,2k,3k...
        for(int i=k; i<n; i++){
            // sum from index i-k to i
            sum = max(sum,prefixSum[i]-prefixSum[i-k]);
        }
        k+=k;
    }
    return sum;
}

int main()
{
}