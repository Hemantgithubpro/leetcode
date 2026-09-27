The **"Wormhole Teleportation"** technique (also known as the **Lee Code / Wormhole traversal algorithm**) allows you to solve [1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?utm_source=gemini) in **$O(N)$ time** and **$O(N)$ space**, avoiding the repeated $O(N^2)$ substring reversals.

---

### The Core Idea

Instead of modifying or reversing string segments in place, think of matching parenthesis pairs `(` and `)` as connected two-way **wormholes**:

1. **Entering a Portal:** Whenever your traversal hits `(` or `)`, you **teleport** to its matching pair in $O(1)$ time.
2. **Changing Gravity (Direction):** Entering a portal flips your walk direction. If you were moving left-to-right (`direction = +1`), you start moving right-to-left (`direction = -1`), and vice versa.
3. **Collecting Characters:** Non-parenthesis characters are simply appended to your result as you pass through them.

---

### Step-by-Step Algorithm

1. **Pre-process Portals:** Use a stack in a first pass to find the matching index for every `(` and `)`. Store these pairings in an array `pair[i]`.
2. **Traverse and Teleport:**
* Start at index `i = 0` moving forward (`step = 1`).
* If `s[i]` is a parenthesis, jump to its pair: `i = pair[i]`, and flip direction: `step = -step`.
* If `s[i]` is a letter, append it to your result string.
* Move to the next position: `i += step`.



---

### C++ Implementation

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;

        // Step 1: Pre-process matching parentheses pairs (Wormholes)
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int open_idx = st.top();
                st.pop();
                pair[open_idx] = i;
                pair[i] = open_idx; // Bi-directional connection
            }
        }

        // Step 2: Traverse using portal teleportation
        string result = "";
        int step = 1; // 1 = Left-to-Right, -1 = Right-to-Left
        
        for (int i = 0; i < n; i += step) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];     // Teleport to matching pair
                step = -step;   // Reverse traversal direction
            } else {
                result += s[i];
            }
        }

        return result;
    }
};

```

---

### Example Walkthrough: `s = "(u(love)i)"`

* **Portal Map:** `pair[0] = 8`, `pair[8] = 0`, `pair[2] = 7`, `pair[7] = 2`
* **Traversal:**
1. `i = 0` (`(`): Teleport to `8`, direction becomes `-1`. Next `i = 7`.
2. `i = 7` (`)`): Teleport to `2`, direction becomes `+1`. Next `i = 3`.
3. `i = 3..6` (`"love"`): Append `'l'`, `'o'`, `'v'`, `'e'`. Next `i = 7`.
4. `i = 7` (`)`): Teleport to `2`, direction becomes `-1`. Next `i = 1`.
5. `i = 1` (`'u'`): Append `'u'`. Next `i = 0`.
6. `i = 0` (`(`): Teleport to `8`, direction becomes `+1`. Next `i = 9` (out of bounds).


* **Output:** `"iloveu"`

---

### Complexity

* **Time Complexity:** $O(N)$ — The first pass builds pairs in $O(N)$, and the traversal visits each index at most twice.
* **Space Complexity:** $O(N)$ — For the `pair` array and stack.