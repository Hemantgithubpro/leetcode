// we're trying to find the 'kth' rank of minimum, like 2nd min element for k=2;
// brute force, i guess
#include <bits/stdc++.h>
using namespace std;

int minCapability(vector<int> &nums, int k)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < nums.size(); i++)
    {
        a.push_back({nums[i], i});
    }
    sort(a.begin(), a.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first < p2.first; // Sort by the first element in ascending order
    });

    // for(int i=0; i<nums.size(); i++){
    //     cout<<a[i].first<<" => "<<a[i].second<<endl;
    // }

    while(k < a.size() && k > 1 && 
         (abs(a[k-1].second - a[k-2].second) == 1)) {
        k++;
    }
    if(k > a.size()) k = a.size();
    int mini = a[k-1].first;
    return mini;
}

int main()
{
    vector<int> nums = {2,3,5,9};
    // 3 5 7 9
    int k = 2;
    cout << minCapability(nums, k);
    // minCapability(nums, k);
    return 0;
}