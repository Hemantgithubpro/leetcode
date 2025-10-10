#include <bits/stdc++.h>
using namespace std;

int maximumEnergy(vector<int> &energy, int k)
{
    int n = energy.size();
    int ans = INT_MIN;
    // brute force: calculate all energy sum for i, then i+k ...
    // for (int i = 0; i < n; i++)
    // {
    //     int pos = i;
    //     int temp = 0;
    //     while (pos < n)
    //     {
    //         temp += energy[pos];
    //         pos += k;
    //     }
    //     ans = max(ans, temp);
    // }
    // return ans;

    // optimal: prefix sum

    vector<int> ps(n);
    for (int i = 0; i < n; i++)
    {
        int pos = i - k;
        if (pos < 0)
        {
            int tempos = i;
            int tempsum = 0;
            while (tempos < n)
            {
                tempsum += energy[tempos];
                tempos += k;
            }
            ans = max(ans, tempsum);
            ps[i] = tempsum;
        }
        else
        {
            ps[i] = ps[i - k] - energy[i - k];
        }
    }
    return *max_element(ps.begin(), ps.end());

    // energy: 5 2 -10 -5 1
    // ps:     5 7  -3 -8 -7
    // sum for i+nk for i=0,k=3; 5-5=0
}

int main()
{
    vector<int> energy = {-9, -2, -6, -5, -8, 3, 0};
    int k = 1;
    cout << maximumEnergy(energy, k);
}