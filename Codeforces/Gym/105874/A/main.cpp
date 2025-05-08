#include <bits/stdc++.h>
using namespace std;

bool check3(int a, int b, int c)
{
    // long a1=a;
    // long b1=b;
    // long c1=c;
    if((long(a+b) <= c) || (long(a+c) <= b) ||(long(c+b) <= a)) return false;
    return true;
}

void solve(vector<int> &arr)
{
    sort(arr.begin(), arr.end(),[](int a, int b){
        return a>b;
    });
    int r=2;
    while(r<arr.size()){
        if(check3(arr[r],arr[r-1],arr[r-2])){
            long long x= arr[r]+arr[r-1]+arr[r-2];
            cout<<x;
            return;
        }
        r++;
    }
    cout<<-1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    vector<int> arr(t);
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    solve(arr);

    return 0;
}
