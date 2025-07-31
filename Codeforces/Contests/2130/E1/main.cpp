#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ask(int k, vector<int> indices)
{
    cout << "? " << k;
    for (int i = 0; i < indices.size(); i++)
    {
        cout << " " << indices[i];
    }
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> ans(n + 1, '.');
        int queries_used = 0;
        bool found_pair = false;
        int open_index = -1, close_index = -1;

        if (n == 1)
        {
            ans[1] = '(';
        }
        else
        {
            for (int j = 2; j <= n; j++)
            {
                vector<int> q = {j, 1};
                int res = ask(2, q);
                queries_used++;
                if (res == 1)
                {
                    found_pair = true;
                    ans[j] = '(';
                    ans[1] = ')';
                    open_index = j;
                    close_index = 1;
                    for (int k = 2; k < j; k++)
                    {
                        ans[k] = ')';
                    }
                    for (int k = j + 1; k <= n; k++)
                    {
                        vector<int> q2 = {j, k};
                        int res2 = ask(2, q2);
                        queries_used++;
                        if (res2 == 1)
                        {
                            ans[k] = ')';
                        }
                        else
                        {
                            ans[k] = '(';
                        }
                    }
                    break;
                }
            }

            if (!found_pair)
            {
                ans[1] = '(';
                for (int j = 2; j <= n; j++)
                {
                    vector<int> q = {1, j};
                    int res = ask(2, q);
                    queries_used++;
                    if (res == 1)
                    {
                        ans[j] = ')';
                    }
                    else
                    {
                        ans[j] = '(';
                    }
                }
            }
        }

        cout << "! ";
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}