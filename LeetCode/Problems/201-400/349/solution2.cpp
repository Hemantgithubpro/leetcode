// this is my try at doing this question through binary search and making it optimal

#include <bits/stdc++.h>
using namespace std;

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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    if(nums1.size()<=nums2.size()){
        
    }
    else{
        
    }

    

}

// nums1=[4,9,5] -> [4,5,9]
// nums2=[9,4,9,8,4] -> [4,4,8,9,9]

int main(){
    
}