# Kadane's Algorithm (Maximum Subarray Sum)

Kadane's algorithm finds the maximum sum of any **contiguous subarray** in `O(n)` time.

---

## 1) Problem Statement

Given an array `a[0..n-1]`, find:

$$
\max_{0 \le l \le r < n} \sum_{i=l}^{r} a_i
$$

This is the maximum subarray sum over all contiguous ranges.

---

## 2) DP Interpretation

Define:

$$
dp_i = \text{maximum sum of a subarray that must end at index } i
$$

Transition:

$$
dp_i = \max(a_i,\ dp_{i-1} + a_i)
$$

Answer:

$$
ans = \max_{0 \le i < n} dp_i
$$

Space optimization: only previous `dp` is needed, so use one variable.

---

## 3) Core Idea (Greedy + DP)

At index `i`, either:
1. Start a new subarray at `i` (sum = `a[i]`), or
2. Extend the best subarray ending at `i-1` (sum = `current + a[i]`).

Choose the better one each time.

---

## 4) Standard C++ (Non-Empty Subarray)

Use this when at least one element must be chosen.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long kadaneMaxSum(const vector<long long>& a) {
	long long bestEnding = a[0];
	long long bestOverall = a[0];

	for (int i = 1; i < (int)a.size(); i++) {
		bestEnding = max(a[i], bestEnding + a[i]);
		bestOverall = max(bestOverall, bestEnding);
	}
	return bestOverall;
}
```

Complexity:
- Time: `O(n)`
- Space: `O(1)`

---

## 5) Kadane with Indices `(l, r)`

Useful when you also need the segment.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct KadaneResult {
	long long maxSum;
	int left;
	int right;
};

KadaneResult kadaneWithIndices(const vector<long long>& a) {
	long long bestEnding = a[0], bestOverall = a[0];
	int tempL = 0, bestL = 0, bestR = 0;

	for (int i = 1; i < (int)a.size(); i++) {
		if (a[i] > bestEnding + a[i]) {
			bestEnding = a[i];
			tempL = i; // start new segment
		} else {
			bestEnding += a[i]; // extend old segment
		}

		if (bestEnding > bestOverall) {
			bestOverall = bestEnding;
			bestL = tempL;
			bestR = i;
		}
	}

	return {bestOverall, bestL, bestR};
}
```

---

## 6) If Empty Subarray Is Allowed

Sometimes problems allow picking no element, so minimum answer is `0`.

Mathematically:

$$
\max\left(0,\ \max_{0 \le l \le r < n} \sum_{i=l}^{r} a_i\right)
$$

Implementation trick:

```cpp
long long kadaneAllowEmpty(const vector<long long>& a) {
	long long bestEnding = 0, bestOverall = 0;
	for (long long x : a) {
		bestEnding = max(0LL, bestEnding + x);
		bestOverall = max(bestOverall, bestEnding);
	}
	return bestOverall;
}
```

---

## 7) Minimum Subarray Sum (Kadane Variant)

For minimum sum contiguous subarray:

$$
dp_i = \min(a_i,\ dp_{i-1} + a_i)
$$

```cpp
long long kadaneMinSum(const vector<long long>& a) {
	long long bestEnding = a[0];
	long long bestOverall = a[0];
	for (int i = 1; i < (int)a.size(); i++) {
		bestEnding = min(a[i], bestEnding + a[i]);
		bestOverall = min(bestOverall, bestEnding);
	}
	return bestOverall;
}
```

---

## 8) Circular Maximum Subarray Sum

For circular array, answer is:

$$
\max(\text{normalMax},\ \text{totalSum} - \text{minSubarraySum})
$$

Important edge case:
- If all elements are negative, `totalSum - minSubarraySum = 0` is invalid for non-empty requirement.
- In that case, return `normalMax` directly.

```cpp
long long maxCircularSubarraySum(const vector<long long>& a) {
	long long normalMax = kadaneMaxSum(a);
	if (normalMax < 0) return normalMax; // all negative

	long long total = 0;
	for (long long x : a) total += x;

	long long minSub = kadaneMinSum(a);
	return max(normalMax, total - minSub);
}
```

---

## 9) Common Mistakes

1. Initializing with `0` when non-empty subarray is required (breaks all-negative arrays).
2. Using `int` when values can overflow; prefer `long long`.
3. Forgetting tie/edge handling when tracking indices.
4. Mixing "empty allowed" and "non-empty required" versions.

---

## 10) Quick Template (CP Use)

```cpp
long long kadane(const vector<long long>& a) {
	long long cur = a[0], ans = a[0];
	for (int i = 1; i < (int)a.size(); i++) {
		cur = max(a[i], cur + a[i]);
		ans = max(ans, cur);
	}
	return ans;
}
```

Use this by default unless the problem explicitly allows empty subarray.
