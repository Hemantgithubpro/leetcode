#include <bits/stdc++.h>
using namespace std;
// now i'll try to optimize it

bool find(vector<int> &digits, int target)
{
    // int left = 0, right = digits.size() - 1;
    // while (left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if (digits[mid] == target) {
    //         return true;
    //     }
    //     if (digits[mid] < target) {
    //         left = mid + 1;
    //     } else {
    //         right = mid - 1;
    //     }
    // }
    unordered_map<int,int> um;
    
    return false;
}

vector<int> findEvenNumbers(vector<int> &digits)
{
    vector<int> result;
    unordered_set<int> unique_numbers;
    sort(digits.begin(), digits.end());
    for (int k = 100; k < 1000; k += 2)
    {
        int p = k % 10;
        if (p % 2 != 0)
            break;
        k /= 10;
        int q = k % 10;
        k /= 10;
        int r = k % 10;
        if (r == 0)
            break;
        // there will be a condn, i guess, i've to implement map, but it will increase time complexity as usual.
    }
    for (auto num : unique_numbers)
    {
        result.push_back(num);
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> digits = {2, 1, 3, 0};
    // sort the digits: {0, 1, 2, 3}
    vector<int> result = findEvenNumbers(digits);
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}