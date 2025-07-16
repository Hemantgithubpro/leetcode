#include <bits/stdc++.h>
using namespace std;

// tle
int maxEvents(vector<vector<int>> &events)
{
    unordered_set<int> d;
    sort(events.begin(), events.end());
    for (int i = events.size() - 1; i >= 0; i--)
    {
        int start = events[i][0];
        int enddate = events[i][1];
        // cout << start << " " << end << endl;
        while (d.find(enddate) != d.end() && enddate > start)
        {
            enddate--;
        }
        // cout << start << endl;
        d.insert(enddate);
    }
    return d.size();
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