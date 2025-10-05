#include <bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>> &events)
{
    int n = events.size();
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    int day = events[0][0];
    int i = 0;
    int count = 0;

    while (!pq.empty() || i < n)
    {

        // optimization start
        if (pq.empty())
        {
            day = events[i][0];
        }
        // optimization over

        while (i < n && events[i][0] == day)
        {
            pq.push(events[i][1]);
            i++;
        }

        if (!pq.empty())
        {
            pq.pop(); // 1 event attended
            count++;
        }

        day++;

        // skip to those events whose end day< current day
        while (!pq.empty() && pq.top() < day)
        {
            pq.pop();
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> events = {{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    // sort(events.begin(), events.end());
    // for (int i = 0; i < events.size(); i++)
    // {
    //     for (int j = 0; j < events[i].size(); j++)
    //     {
    //         cout << events[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << maxEvents(events);
}