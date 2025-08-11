## I tried my best in my.cpp

- ig this is all 'mod' thing, i'm storing it in prefix multiplication array, and then using it to calculate the result for each query. but the modding makes the answer inaccurate

## Brute force way, works on this constraints.

- for each query, just calculate the product of the range directly
- this is obviously not optimal, but it works

# Soln

````cpp
vector<int> productQueries(int n, const vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        vector prefix {0};
        while (n) {
            const int j = __builtin_ctz(n);
            prefix.push_back(prefix.back() + j);
            n -= 1 << j;
        }
        n = prefix.back();
        vector ans {1}; ans.reserve(n);
        for (int i = 1; i <= n; i++)
            ans.push_back((ans.back() << 1) % MOD);
        vector<int> ret; ret.reserve(queries.size());
        for (const auto& q : queries)
            ret.push_back(ans[prefix[q[1] + 1] - prefix[q[0]]]);
        return ret;
    }
    ```
```
