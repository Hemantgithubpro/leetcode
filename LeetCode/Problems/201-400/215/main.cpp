#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    // build a min heap of size k, if an element greater than top comes, replace it
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int n : nums)
    {
        pq.push(n);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top(); // O(n.logk)
}