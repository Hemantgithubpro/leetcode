#include <bits/stdc++.h>
using namespace std;

char kthCharacter(int k)
{
    int shift = __builtin_popcount(k - 1);
    return 'a' + shift;
}