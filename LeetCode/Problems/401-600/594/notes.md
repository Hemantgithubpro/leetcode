


## Rough

1. 1,3,2,2,5,2,3,7
   1 2 2 2 3 3 5 7

# Did it myself.
# Can be optimized:
- For each number num in the map, check if num + 1 also exists in the map.
If yes, the pair (num, num + 1) forms a valid harmonious subsequence.
Calculate the length of this subsequence: count[num] + count[num + 1].
- Edge Cases:
If all numbers are the same (e.g., [2, 2, 2]), return 0 (no valid pair).
If no two numbers differ by 1 (e.g., [1, 5, 10]), return 0.
```cpp
int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        // Step 1: Count frequencies of each number
        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxLength = 0;

        // Step 2: Check all possible (num, num+1) pairs
        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                int currentLength = count + frequencyMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
    ```