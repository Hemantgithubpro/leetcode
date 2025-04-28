#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &a)
{
    return (a[0] == a[1] && a[1] == a[2]);
}

string solve(vector<int> &a)
{

    // Make a[0] equal to a[1] by transferring from a[2]
    int k = a[1] - a[0];
    a[2] -= k;
    a[0] += k;

    // Check if we've created any negative values
    if (a[2] < 0 || a[0] < 0 || a[1] < 0)
    {
        return "NO";
    }

    // Check if the resulting order is invalid
    if (a[2] < a[1] || a[1] < a[0])
    {
        return "NO";
    }

    // If all values are already equal, we're done
    if (isValid(a))
    {
        return "YES";
    }

    // If a[2] is even, we can make all values equal
    // This is because we can remove 2 from a[2] and add 1 to both a[0] and a[1] repeatedly
    int diff = a[2] - a[0];
    // Check if we can distribute the remaining difference evenly
    if (diff % 2 == 0 && diff / 2 == (a[2] - a[1]))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        vector<int> a(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        cout << solve(a) << endl;
    }
}
