#include <bits/stdc++.h>
using namespace std;

// did it in first try.
int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int count = 0;
    int i = 0, j = 0;
    while (i < players.size() && j < trainers.size())
    {
        if (players[i] > trainers[j])
        {
            j++;
        }
        else
        {
            count++;
            i++;
            j++;
        }
    }
    return count;
}

int main()
{
    
}