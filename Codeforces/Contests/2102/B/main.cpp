#include <bits/stdc++.h>
using namespace std;

int mod(int a)
{
    if (a > 0)
        return a;
    return -1 * a;
}

int findposoftobe(int tobe, vector<int> &a)
{
    int posoftobe = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == tobe)
            posoftobe = i;
    }
    return posoftobe;
}

void solve(int n, vector<int> &arr)
{
    int tobemedian = arr[0];
    sort(arr.begin(), arr.end());
    float median = 0;
    // if no. of elements is odd
    if (n % 2 == 1)
    {
        int posttobe = findposoftobe(tobemedian, arr);

        // median = arr[(n+1)/2])
        // int ne=n/2;
        // median=arr[ne];
        // if(tobemedian==median){
        //     cout<<"YES"<<endl;
        //     return;
        // }
        cout << "YES" << endl;
        return;
    }
    else
    {
        // median = 0.5(arr[n/2]+arr[n/2 +1])
        int no1 = ((n - 1) / 2);
        // int no2=no1+1;
        // median=0.5*(arr[no1]+arr[no2]);
        median = arr[no1];
        int posttobe = findposoftobe(tobemedian, arr);
        if (posttobe == no1)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            if (posttobe > no1)
            {
                int x = posttobe - no1;
                int y = 0;
                for (int i = 0; i < n; i++)
                {
                    // if(tobemedian>0 && )
                }
            }
            else
            {
                int x = no1 - posttobe;
                for (int i = 0; i < n; i++)
                {
                    // if(tobemedian>0 && )
                }
            }
        }
        if (int(median) == tobemedian)
        {
            cout << "YES" << endl;
            return;
        }
    }
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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
