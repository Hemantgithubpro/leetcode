# Approach to Problem 2163: Minimum Difference in Sums of Two Parts
To minimize `sumfirst - sumsecond`, we aim to:

- **Minimize `sumfirst`**:  
    Select the smallest possible *n* elements from the left side.

- **Maximize `sumsecond`**:  
    Select the largest possible *n* elements from the right side.
    
# claude notes
## 1. Understanding the Problem Structure

**Given**: Array of size `3*n`
**Goal**: Remove exactly `n` elements, then split remaining `2*n` elements into two equal parts of size `n` each

```
Original: [a, b, c, d, e, f] (3*n = 6, so n = 2)
Remove 2 elements: [a, c, d, f] (remaining 2*n = 4)
Split: [a, c] | [d, f]
Difference: (a + c) - (d + f)
```

## 2. Key Insight: We Don't Actually Remove Elements

Here's the crucial realization: **We don't need to explicitly remove elements!**

Instead, we can think of it as:
- **Choose `n` elements for the first part** (from positions 0 to some middle point)
- **Choose `n` elements for the second part** (from some middle point to end)
- The remaining `n` elements are "implicitly removed"

## 3. The Split Point Strategy

Since the remaining elements must be divided into two consecutive parts, there must be a **split point** where:
- First part: `n` elements from left side
- Second part: `n` elements from right side

```
nums: [7, 9, 5, 8, 1, 3] (n = 2)
      
Split after position 1: [7, 9] | [5, 8, 1, 3]
- First part: choose 2 from [7, 9] → can only choose both → sum = 16
- Second part: choose 2 from [5, 8, 1, 3] → choose best 2 → sum = 8+5 = 13
- Difference = 16 - 13 = 3

Split after position 3: [7, 9, 5, 8] | [1, 3]  
- First part: choose 2 from [7, 9, 5, 8] → choose smallest 2 → sum = 5+7 = 12
- Second part: choose 2 from [1, 3] → can only choose both → sum = 4
- Difference = 12 - 4 = 8
```

## 4. Optimization Strategy

To minimize `sumfirst - sumsecond`, we want:
- **Minimize `sumfirst`**: Choose the smallest possible `n` elements from the left side
- **Maximize `sumsecond`**: Choose the largest possible `n` elements from the right side

## 5. Dynamic Programming Approach

**For each possible split point, precompute:**

### Left side (minLeft[i]):
*"What's the minimum sum of `n` elements I can choose from `nums[0..i]`?"*

```cpp
// Use max heap to keep track of n smallest elements
priority_queue<int> maxHeap;
for (int i = 0; i < nums.size(); i++) {
    maxHeap.push(nums[i]);
    sum += nums[i];
    
    if (maxHeap.size() > n) {
        sum -= maxHeap.top();  // Remove largest element
        maxHeap.pop();
    }
    
    if (maxHeap.size() == n) {
        minLeft[i] = sum;  // Sum of n smallest elements
    }
}
```

### Right side (maxRight[i]):
*"What's the maximum sum of `n` elements I can choose from `nums[i..end]`?"*

```cpp
// Use min heap to keep track of n largest elements  
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int i = nums.size() - 1; i >= 0; i--) {
    minHeap.push(nums[i]);
    sum += nums[i];
    
    if (minHeap.size() > n) {
        sum -= minHeap.top();  // Remove smallest element
        minHeap.pop();
    }
    
    if (minHeap.size() == n) {
        maxRight[i] = sum;  // Sum of n largest elements
    }
}
```

## 6. Why Priority Queues Work

### For minimum sum (left side):
- We want to keep the `n` **smallest** elements
- When we have more than `n` elements, we remove the **largest** one
- So we use a **max heap** to easily access and remove the largest element

### For maximum sum (right side):
- We want to keep the `n` **largest** elements  
- When we have more than `n` elements, we remove the **smallest** one
- So we use a **min heap** to easily access and remove the smallest element

## 7. Valid Split Points

The split point `i` must satisfy:
- `i >= n-1`: We need at least `n` elements on the left side
- `i < 2*n`: We need at least `n` elements on the right side

## 8. Final Answer

For each valid split point `i`:
```cpp
result = min(result, minLeft[i] - maxRight[i+1]);
```

This gives us the minimum possible difference by trying all valid ways to split the array and choosing the optimal elements from each side.

## Example Walkthrough

```
nums = [7, 9, 5, 8, 1, 3], n = 2

minLeft: [∞, ∞, 12, 12, 8, 4]  // min sum of 2 elements from left
maxRight: [16, 17, 13, 11, 4, ∞] // max sum of 2 elements from right

Valid splits (i from 1 to 3):
i=1: minLeft[1] - maxRight[2] = ∞ - 13 = ∞ (invalid)
i=2: minLeft[2] - maxRight[3] = 12 - 11 = 1 ✓
i=3: minLeft[3] - maxRight[4] = 12 - 4 = 8

Answer: min(1, 8) = 1
```

The beauty of this approach is that it systematically considers all possible ways to split the array while efficiently computing the optimal choices for each side using priority queues.