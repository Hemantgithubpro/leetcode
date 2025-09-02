#include <bits/stdc++.h>
using namespace std;

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    int n = classes.size();
    priority_queue<pair<double, int>> pq;

    for (int i = 0; i < n; i++)
    {
        int pass = classes[i][0];
        int total = classes[i][1];
        double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
        pq.push({gain, i});
    }

    while (extraStudents--)
    {
        auto top = pq.top();
        pq.pop();
        int idx = top.second;

        classes[idx][0]++;
        classes[idx][1]++;

        int pass = classes[idx][0];
        int total = classes[idx][1];
        double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
        pq.push({gain, idx});
    }

    double ans = 0.0;
    for (auto &c : classes)
    {
        ans += (double)c[0] / c[1];
    }

    return ans / n;
}

int main()
{
}