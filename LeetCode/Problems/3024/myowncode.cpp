#include <bits/stdc++.h>
using namespace std;

// just did silly mistakes here, but did it. learnt nothing new.
string triangleType(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];
    if (a + b <= c)
        return "none";
    cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl;
    if (a == b)
    {
        if (b == c)
            return "equilateral";
        else
            return "isosceles";
    }
    else if (b == c)
        return "isosceles";
    return "scalene";
}

int main()
{
    vector<int> nums={9,10,9};
    cout<<triangleType(nums);
}