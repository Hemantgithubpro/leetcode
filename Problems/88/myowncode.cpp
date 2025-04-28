#include <bits/stdc++.h>
using namespace std;
// made logic but not working
vector<int> inser(vector<int> &b, int index, int sizeofarr, int numb)
{
    // if index=2, it means insert between 1&2
    for (int i = sizeofarr - 1; i > index; i--)
    {
        b[i] = b[i - 1];
    }
    b[index] = numb;
    return b;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l = 0;
    int r = 0;
    //  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    int sizeofarr = n + m;
    while (r < n && l < m)
    {
        if (nums1[l] < nums2[r])
            l++;
        else if (nums1[l] >= nums2[r])
        {
            nums1 = inser(nums1, l, sizeofarr, nums2[r]);
            r++;
        }
    }
    if (l == m)
    {
        l = m + r;
        while (r < n)
        {
            nums1[l] = nums2[r];
            r++;
            l++;
        }
    }
}

int main()
{
    vector<int> ab={4,0,0,0,0,0};
    int m=1;
    vector<int> ab2={1,2,3,5,6};
    int n=5;
    for(int i=0; i<ab.size(); i++){
        cout<<ab[i]<<" ";
    }
    
    cout<<endl;
    merge(ab,m,ab2,n);
    
    for(int i=0; i<ab.size(); i++){
        cout<<ab[i]<<" ";
    }
}