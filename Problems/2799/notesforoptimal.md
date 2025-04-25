## 🧍‍♂️ Example Walkthrough

- For `nums = [1, 3, 1, 2, 2]` and `k = 3`:

  - Initialize `left = 0`, `res = 0`, `mpp = {}`

  - Iterate `i` from **0 to 4**:
    1. `i = 0`: add `1` → `mpp = {1:1}` (size 1) → **no full window**
    2. `i = 1`: add `3` → `mpp = {1:1, 3:1}` (size 2) → **no full window**
    3. `i = 2`: add `1` → `mpp = {1:2, 3:1}` (size 2) → **no full window**
    4. `i = 3`: add `2` → `mpp = {1:2, 3:1, 2:1}` (size 3 == k)
       - while `size == k`:
         - `res += 5 - 3 = 2` → `res = 2`
         - remove `nums[left] = 1` → `mpp = {1:1, 3:1, 2:1}`, `left = 1`
         - still full →
           - `res += 2` → `res = 4`
           - remove `nums[left] = 3` → `mpp = {1:1, 2:1}`, `left = 2`
    5. `i = 4`: add `2` → `mpp = {1:1, 2:2}` (size 2) → **no full window**

- Return `res = 4`

## CODE

```cpp
    int countCompleteSubarrays(vector<int>& nums, int left = 0, int res = 0) {
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                res += nums.size() - i;
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return res;
    }
```
