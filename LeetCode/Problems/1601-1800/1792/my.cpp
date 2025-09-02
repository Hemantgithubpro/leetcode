#include <bits/stdc++.h>
using namespace std;
using info = tuple<double, int, int>;
info A[100000];
double maxAverageRatio(vector<vector<int>> &classes, int k)
{
    // avg pass ratio: sum of all (pass[i]) in a class / sum of all total in a class

    // vector<double> passratios;
    // for (int i = 0; i < classes.size(); i++)
    // {
    //     double p = (double)classes[i][0] / (double)classes[i][1];
    //     passratios.push_back(p);
    // }
    // sort(passratios.begin(), passratios.end());

    const int n = classes.size();
    double sum = 0.0;
    int i = 0;
    for (auto &pq : classes)
    {
        int p = pq[0], q = pq[1];
        sum += (double)p / q;
        double inc = (double)(q - p) / (q * (q + 1.0));
        A[i++] = {inc, p, q};
    }

    make_heap(A, A + n);

    for (int i = 0; i < k; i++)
    {
        pop_heap(A, A + n);
        auto [r, p, q] = A[n - 1];
        if (r == 0)
            break; // early stop

        // Add the current inc to the sum
        sum += r;
        double r2 = (double)(q - p) / ((q + 1.0) * (q + 2.0));
        A[n - 1] = {r2, p + 1, q + 1};
        push_heap(A, A + n);
    }

    return sum / n;
}

int main()
{
    int a = 5;
    int b = 2;
    double c = (double)a / (double)b;
    cout << c;
    return 0;
}