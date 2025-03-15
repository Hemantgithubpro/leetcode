#include <bits/stdc++.h>
using namespace std;

// it returns the index of the founded target in array
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int minCapability(vector<int>& nums, int k) {
	vector<pair<int, int>> a;
	for(int i=0; i<nums.size(); i++){
		a.push_back({nums[i],i});
	}

	sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first < p2.first; // Sort by the first element in ascending order
	});

	int ans=0;
	for(int i=0; i<k; i++){
		if(a[i].second<a[i+1].second+1 || a[i].second<a[i+1].second-1) ans+=a[i].first;
	}
	return ans;
}

// nums=[2,7,9,3,1]
// vector<pair<int,int>> n = [<2,0>,<7,1>,<9,2>,<3,3>,<1,4>]
// sorted n= [<1,4>,<2,0>,<3,3>,<7,1>,<9,2>]
// k=2,

// nums=[2,3,5,9]
// vector<pair<int,int>> n = [<2,0>,<3,1>,<5,2>,<9,3>]
// sorted n= [<2,0>,<3,1>,<5,2>,<9,3>]
// 

int main(){
	vector<int> nums={2,7,9,3,1};
	cout<<minCapability(nums,3);
}