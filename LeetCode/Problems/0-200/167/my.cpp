#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();

        // left and right pointers
        int left = 0;
        int right = n - 1;

        while (right > left)
        {
            if (numbers[left] + numbers[right] == target)
                return {left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return {-1};
    }
};