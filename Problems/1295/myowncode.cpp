#include <bits/stdc++.h>
using namespace std;
// this is a brute force method, i think it could be optimized further
// Time complexity is O(n log m) where n is the number of elements in the array and m is the maximum number of digits in the numbers
//  and space complexity is O(1) as we are not using any extra space

bool isEvennoofDigits(int n) {
    int cnt=0;
    while(n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt % 2 == 0;
}

int findNumbers(vector<int>& nums) {
    int cnt = 0;
    for(int i=0;i<nums.size();i++){
        if(isEvennoofDigits(nums[i])){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << findNumbers(nums);
}