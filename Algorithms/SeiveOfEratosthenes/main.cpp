#include <bits/stdc++.h>
using namespace std;

int no_of_prime_till_n(int n)
{
    // my implementation: somewhat wrong
    // vector<bool> v(n+1, true);
    // v[0] = false, v[1] = false;
    // int ans = 0;
    // for (int i = 2; i * i <= n; i++)
    // {
    //     if (v[i] == true)
    //     {
    //         ans++;
    //         int j = 2;
    //         long long temp;
    //         while (temp < n)
    //         {
    //             temp = i;
    //             temp *= j;
    //             v[temp] = false;
    //             j++;
    //         }
    //     }
    // }
    // return ans;

    // correct implementation
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {

            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            res.push_back(p);
        }
    }
    return res.size();
}

int main()
{
    int n = 10;
    cout << no_of_prime_till_n(n);
}