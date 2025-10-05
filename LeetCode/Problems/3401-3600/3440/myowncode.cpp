#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
{
    vector<int> gap;
    int n = startTime.size();
    gap.push_back(startTime[0]);
    for (int i = 1; i < n; i++)
    {
        int temp = startTime[i] - endTime[i - 1];
        gap.push_back(temp);
    }
    gap.push_back(eventTime - endTime[n - 1]);

    n = gap.size();
    vector<int> maxRightFree(n, 0);
    vector<int> maxLeftFree(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        maxRightFree[i] = max(maxRightFree[i + 1], gap[i + 1]);
    }
    for (int i = 1; i < n; i++)
    {
        maxLeftFree[i] = max(maxLeftFree[i - 1], gap[i - 1]);
    }

    int result = 0;
    for (int i = 1; i < n; i++)
    {
        int currEventTime = endTime[i - 1] - startTime[i - 1]; // duration of event d

        // case 1 moving completely out
        if (currEventTime <= max(maxLeftFree[i - 1], maxRightFree[i]))
        {
            result = max(result, gap[i - 1] + currEventTime + gap[i]);
        }

        // case 2 shift left or right
        result = max(result, gap[i - 1] + gap[i]);
    }
    return result;
}

int main()
{
}
