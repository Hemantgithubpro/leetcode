#include <bits/stdc++.h>
using namespace std;

int findmin(vector<int> &arr)
{
    int mini = INT_MAX;
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < mini)
        {
            mini=arr[i];
            index = i;
        }
    }
    return index;
}

int main(){
    vector<int> arr={12,54,3,89,57};
    // cout<<arr[3];
    int index=findmin(arr);
    cout<<index;
}