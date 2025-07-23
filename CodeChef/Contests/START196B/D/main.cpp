#include <bits/stdc++.h>
using namespace std;

int nll, kll;
vector<int> aa, bb;

struct Node
{
    int sf, st;
    bool ef, et;
};

vector<Node> tr;

Node mg(Node &l, Node &r)
{
    Node res;

    res.sf = l.sf;
    if (l.ef)
    {
        res.sf += r.st;
        res.ef = r.et;
    }
    else
    {
        res.sf += r.sf;
        res.ef = r.ef;
    }

    res.st = l.st;
    if (l.et)
    {
        res.st += r.st;
        res.et = r.et;
    }
    else
    {
        res.st += r.sf;
        res.et = r.ef;
    }
    return res;
}

void bld(int v, int s, int e)
{
    if (s == e)
    {
        bool p = (aa[s] + kll < bb[s]);
        bool q = (bb[s] + kll < aa[s]);

        tr[v].ef = p;
        tr[v].sf = p ? bb[s] : aa[s];

        tr[v].et = !q;
        tr[v].st = q ? aa[s] : bb[s];
        return;
    }
    int m = s + (e - s) / 2;
    bld(2 * v, s, m);
    bld(2 * v + 1, m + 1, e);
    tr[v] = mg(tr[2 * v], tr[2 * v + 1]);
}

void updt(int v, int s, int e, int i)
{
    if (s == e)
    {
        bool p = (aa[i] + kll < bb[i]);
        bool q = (bb[i] + kll < aa[i]);

        tr[v].ef = p;
        tr[v].sf = p ? bb[i] : aa[i];

        tr[v].et = !q;
        tr[v].st = q ? aa[i] : bb[i];
        return;
    }
    int m = s + (e - s) / 2;
    if (i <= m)
        updt(2 * v, s, m, i);
    else
        updt(2 * v + 1, m + 1, e, i);
    tr[v] = mg(tr[2 * v], tr[2 * v + 1]);
}

void solve()
{
    int nn, kk;
    cin >> nn >> kk;
    nll = nn;
    kll = kk;
    aa.resize(nn);
    bb.resize(nn);
    for (int i = 0; i < nn; ++i)
        cin >> aa[i];
    for (int i = 0; i < nn; ++i)
        cin >> bb[i];

    tr.assign(4 * nn, Node());
    bld(1, 0, nn - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int t, p, x;
        cin >> t >> p >> x;
        p--;

        if (t == 1)
        {
            aa[p] = x;
        }
        else
        {
            bb[p] = x;
        }
        updt(1, 0, nn - 1, p);
        cout << tr[1].sf << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    return 0;
}
