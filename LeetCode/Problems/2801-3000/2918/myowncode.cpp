#include <bits/stdc++.h>
using namespace std;
long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    long long sum1 = 0;
    long long sum2 = 0;
    int noof0in1 = 0;
    int noof0in2 = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (nums1[i] == 0)
            noof0in1++;
        sum1 += nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (nums2[i] == 0)
            noof0in2++;
        sum2 += nums2[i];
    }

    if (noof0in1 == 0 && noof0in2 == 0 && sum1 == sum2)
        return sum1;

    if (sum1 != sum2)
    {
        if (noof0in1 == 0 && noof0in2 == 0)
            return -1;
        else if (noof0in1 == 0 && noof0in2 != 0)
        {
            sum2 += noof0in2;
            if (sum1 == sum2)
                return sum1;
            else
            {
                if (sum1 > sum2)
                    return sum1;
                else
                    return -1;
            }
        }
        else if (noof0in1 != 0 && noof0in2 == 0)
        {
            sum1 += noof0in1;
            if (sum1 == sum2)
                return sum1;
            else
            {
                if (sum1 > sum2)
                    return -1;
                else
                    return sum2;
            }
        }
        else
        {
            sum1 += noof0in1;
            sum2 += noof0in2;
            if (sum1 == sum2)
                return sum1;
            else
            {
                if (sum1 > sum2)
                    return sum1;
                else
                    return sum2;
            }
        }
    }
    else
    {
        if (noof0in1 != 0)
        {
            if (noof0in2 != 0)
            {
                sum1 += noof0in1;
                sum2 += noof0in2;
                if (sum1 == sum2)
                    return sum1;
                else if (sum1 > sum2)
                    return sum1;
                else
                    return sum2;
            }
            else
            {
                sum1 += noof0in1;
                if (sum1 == sum2)
                    return sum1;
                else if (sum1 > sum2)
                    return sum1;
                else
                    return sum2;
            }
        }
        else
        {
            if (noof0in2 != 0)
            {
                sum2 += noof0in2;
                if (sum1 == sum2)
                    return sum1;
                else if (sum1 > sum2)
                    return sum1;
                else
                    return sum2;
            }
            else
                return sum1;
        }
    }
    return -1;
}
int main()
{
    // vector<int> nums1={3,2,0,1,0};
    // vector<int> nums2={6,5,0};

    vector<int> nums1 = {0,0,10,10,12,0,13,6,0,2,10};
    vector<int> nums2 = {24,5,12,22};
    // expected soln=-1, my ans=67, why!
    cout << minSum(nums1, nums2);
}