#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, Q;
    cin >> N >> Q;

    string server = "";
    vector<string> pcs(N + 1, "");

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int p;
            cin >> p;
            pcs[p] = server;
        }
        else if (type == 2)
        {
            int p;
            string s;
            cin >> p >> s;
            pcs[p] += s;
        }
        else if (type == 3)
        {
            int p;
            cin >> p;
            server = pcs[p];
        }
    }

    cout << server << endl;

    return 0;
}