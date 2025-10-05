#include <bits/stdc++.h>
using namespace std;

class FindSumPairs
{
    vector<int> nums1;
    vector<int> nums2;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
    }

    void add(int index, int val)
    {
        nums2[index] += val;
    }

    int bsearch(vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        int result = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }

    int count(int tot)
    {
        vector<int> a = nums1;
        vector<int> b = nums2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int cnt = 0;
        // we traverse thru b, and take form a[0]
        for (int i = 0; i < a.size(); i++)
        {
            int target = tot - a[i];
            int bs = bsearch(b, target);
            if (bs >= 0) cnt++;
            while(bs<b.size()-1 && b[bs]==b[bs+1]) cnt++;
        }
        return cnt;
    }
};

int main()
{
}