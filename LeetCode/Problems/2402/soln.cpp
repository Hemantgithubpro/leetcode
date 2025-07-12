#include <bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    // Sort meetings by start time
    sort(meetings.begin(), meetings.end());

    // Priority queue to track available rooms (min heap for lowest room number)
    priority_queue<int, vector<int>, greater<int>> available;
    // Priority queue to track room end times: {end_time, room_number}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> used;

    // Initialize all rooms as available
    for (int i = 0; i < n; ++i)
    {
        available.push(i);
    }

    // Track number of meetings per room
    vector<int> meetingCount(n, 0);

    for (const auto &meeting : meetings)
    {
        long long start = meeting[0], end = meeting[1];

        // Free up rooms that have finished their meetings
        while (!used.empty() && used.top().first <= start)
        {
            available.push(used.top().second);
            used.pop();
        }

        // If no rooms are available, delay the meeting
        if (available.empty())
        {
            // Get the earliest ending meeting
            auto [endTime, room] = used.top();
            used.pop();
            // Update end time for delayed meeting
            end = endTime + (end - start);
            start = endTime;
            available.push(room);
        }

        // Assign the meeting to the lowest numbered available room
        int room = available.top();
        available.pop();
        meetingCount[room]++;
        used.push({end, room});
    }

    // Find the room with maximum meetings
    int maxMeetings = 0, resultRoom = 0;
    for (int i = 0; i < n; ++i)
    {
        if (meetingCount[i] > maxMeetings)
        {
            maxMeetings = meetingCount[i];
            resultRoom = i;
        }
    }

    return resultRoom;
}

int main()
{
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};

    cout << mostBooked(n, meetings);
}