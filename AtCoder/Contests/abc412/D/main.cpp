#include <bits/stdc++.h>
using namespace std;

// map each unordered pair (i<j) to a bit‐index in [0..N*(N-1)/2)
int edgeId[8][8];

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // build edgeId lookup
    int K = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            edgeId[i][j] = K++;

    // read input graph mask
    int init_mask = 0;
    for (int e = 0; e < M; e++)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        if (A > B)
            swap(A, B);
        init_mask |= (1 << edgeId[A][B]);
    }

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    int best = INT_MAX;
    // walk all N! permutations
    do
    {
        // build adjacency from p
        static bool adj[8][8];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i][j] = false;

        for (int i = 0; i < N; i++)
        {
            int j = p[i];
            adj[i][j] = adj[j][i] = true;
        }
        // check every vertex deg==2
        bool ok = true;
        for (int i = 0; i < N && ok; i++)
        {
            int deg = 0;
            for (int j = 0; j < N; j++)
                if (adj[i][j])
                    deg++;
            if (deg != 2)
                ok = false;
        }
        if (!ok)
            continue;

        // build mask for this target
        int target_mask = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (adj[i][j])
                    target_mask |= (1 << edgeId[i][j]);
            }
        }
        // cost = symmetric difference
        int diff = init_mask ^ target_mask;
        int ops = __builtin_popcount(diff);
        best = min(best, ops);

    } while (next_permutation(p.begin(), p.end()));

    cout << best << "\n";
    return 0;
}
