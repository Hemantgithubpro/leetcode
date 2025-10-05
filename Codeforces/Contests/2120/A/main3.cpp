#include <bits/stdc++.h>
using namespace std;

void solve(int l1, int b1, int l2, int b2, int l3, int b3)
{
    if(l2+l3<l1){
        cout<<"NO"<<endl;
        return;
    }
    if(b2+b3<b1){
        cout<<"NO"<<endl;
        return;
    }
    // we know l1>=l2>=l3 and b1>=b2>=b3
    if (l1 >= b1)
    { // we need to stack it up
        if (l2 + l3 == l1)
        {
            if (b2 == b3)
            {
                if (b1 + b2 == l1 + l3)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (l2 == l1 && l3 == l1)
        {
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    else
    { // we need to put it in right
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        solve(l1, b1, l2, b2, l3, b3);
    }

    return 0;
}