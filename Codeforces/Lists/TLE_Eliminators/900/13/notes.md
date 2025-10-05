# TLE Eliminators 900 - 13
### Mex
```cpp
int findMex(vector<int>& a) {
    int n = a.size();
    vector<bool> present(n + 1, false);
    for (int x : a) {
        if (x >= 0 && x <= n) present[x] = true;
    }
    for (int i = 0; i <= n; ++i) {
        if (!present[i]) return i;
    }
    return n + 1;
}
```

## Approach to the question
- one is to 