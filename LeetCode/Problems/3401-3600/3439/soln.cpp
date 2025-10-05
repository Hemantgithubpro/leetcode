#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
{
    vector<int> gap;
    gap.push_back(startTime[0]);
    for (int i = 1; i < startTime.size(); i++)
    {
        int temp = startTime[i] - endTime[i - 1];
        gap.push_back(temp);
    }
    gap.push_back(eventTime - endTime.back());

    // sliding window of length k+1
    int sum = 0, temp = 0;
    for (int i = 0; i < gap.size(); i++)
    {
        temp += gap[i] - ((i >= k + 1) ? gap[i - (k + 1)] : 0);
        sum = max(sum, temp);
    }
    return sum;
}

int main()
{
}
