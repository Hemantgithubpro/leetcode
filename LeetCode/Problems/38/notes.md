# Count and Say Problem - Solution Notes

## Approach 1: Iterative (For Loop)

### 💡 Intuition
The Count and Say sequence is a recursive sequence of digit strings where each term describes the previous one.
The base case is "1", and from there, each new string is constructed by reading off the digits of the previous string, counting the number of digits in groups of the same digit.

**For example:**
- 1 → one 1 → "11"
- 11 → two 1s → "21"
- 21 → one 2, then one 1 → "1211"
- and so on...

This resembles a run-length encoding strategy applied recursively.

### 🛠️ Approach
1. Start from the base case: "1".
2. Iterate n - 1 times:
   - In each iteration, build the new string by reading and encoding the current string.
3. To construct the next string:
   - Count consecutive occurrences of the same digit.
   - Append `<count><digit>` to the result.
4. Repeat until the nth term is generated.

### ⏱️ Complexity
- **Time Complexity**: O(2^n)
  - This is because each term approximately doubles in size compared to the previous term (though not exactly). Therefore, constructing each term takes time proportional to its length, and the final term is roughly of length O(2^n).

- **Space Complexity**: O(2^n)
  - For the same reason: we store and build a string that grows exponentially.

### ✅ Code Implementation

```dart
class Solution {
  String countAndSay(int n) {
    String result = '1';
    for (int i = 1; i < n; i++) {
      result = _describe(result);
    }
    return result;
  }

  String _describe(String s) {
    StringBuffer result = StringBuffer();
    int count = 1;
    
    for (int i = 1; i < s.length; i++) {
      if (s[i] == s[i - 1]) {
        count++;
      } else {
        result.write('$count${s[i - 1]}');
        count = 1;
      }
    }
    
    result.write('$count${s[s.length - 1]}');
    return result.toString();
  }
}
```

## Approach 2: Recursive

### 💡 Intuition
The problem is asking us to generate the n-th term in the Count and Say sequence. Each term describes the previous term by counting consecutive digits. This naturally hints at a recursive solution, where each term depends directly on the term before it.

The base case is "1", and each subsequent term is a "verbal description" of the digits in the previous term. This makes recursion a good fit since you can build from the base case up to the desired term.

### 🛠️ Approach
**Step-by-step:**
1. **Base Case:**
   - If n == 1, return "1".

2. **Recursive Call:**
   - Recursively get the (n-1)th term.

3. **Run-Length Encoding (RLE):**
   - Use a helper function to process the string and count consecutive occurrences of each digit.
   - Append the count and digit to build the current term.

4. **Return Result:**
   - Return the encoded string as the n-th term.

**RLE Logic in Detail:**
- Traverse the input string s.
- Keep track of a group of identical digits.
- When the digit changes, append the count and digit to the result.
- At the end, append the final group.

### ⏱️ Complexity
- **Time Complexity**: O(2^n)
  - Because each string approximately doubles in size from the previous term, and we compute RLE for each one recursively, the total time is exponential in n.

- **Space Complexity**: O(2^n)
  - Due to recursive call stack and the exponential growth in string size, space also grows exponentially.

### ✅ Code Implementation

```dart
class Solution {
  String countAndSay(int n) {
    if (n == 1) return "1";
    String previous = countAndSay(n - 1);
    return rle(previous);
  }

  String rle(String s) {
    int i = 1;
    int start = 0;
    StringBuffer result = StringBuffer();
    int n = s.length;

    while (i < n) {
      if (s[i] == s[i - 1]) {
        // Same digit group
      } else {
        result.write("${i - start}${s[i - 1]}");
        start = i;
      }
      i++;
    }

    // Handle the last group
    result.write("${i - start}${s[i - 1]}");
    return result.toString();
  }
}
```