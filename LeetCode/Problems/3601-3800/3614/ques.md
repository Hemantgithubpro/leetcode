# Problem

You are given a string `s` consisting of lowercase English letters and the special characters: `'*'`, `'#'`, and `'%'`.

You are also given an integer `k`.

Build a new string `result` by processing `s` from left to right according to the following rules:

- If the current character is a lowercase English letter, append it to `result`.
- `'*'` removes the last character from `result` (if it exists).
- `'#'` duplicates the current `result` and appends it to itself.
- `'%'` reverses the current `result`.

Return the **k-th character** (0-indexed) of the final string `result`.

If `k` is out of bounds, return `'.'`.

---

## Example 1

### Input
```text
s = "a#b%*"
k = 1
```

### Output
```text
"a"
```

### Explanation

| i | s[i] | Operation | Current result |
|---|------|-----------|----------------|
| 0 | `'a'` | Append `'a'` | `"a"` |
| 1 | `'#'` | Duplicate result | `"aa"` |
| 2 | `'b'` | Append `'b'` | `"aab"` |
| 3 | `'%'` | Reverse result | `"baa"` |
| 4 | `'*'` | Remove last character | `"ba"` |

Final result: `"ba"`

Character at index `k = 1` is `'a'`.

---

## Example 2

### Input
```text
s = "cd%#*#"
k = 3
```

### Output
```text
"d"
```

### Explanation

| i | s[i] | Operation | Current result |
|---|------|-----------|----------------|
| 0 | `'c'` | Append `'c'` | `"c"` |
| 1 | `'d'` | Append `'d'` | `"cd"` |
| 2 | `'%'` | Reverse result | `"dc"` |
| 3 | `'#'` | Duplicate result | `"dcdc"` |
| 4 | `'*'` | Remove last character | `"dcd"` |
| 5 | `'#'` | Duplicate result | `"dcddcd"` |

Final result: `"dcddcd"`

Character at index `k = 3` is `'d'`.

---

## Example 3

### Input
```text
s = "z*#"
k = 0
```

### Output
```text
"."
```

### Explanation

| i | s[i] | Operation | Current result |
|---|------|-----------|----------------|
| 0 | `'z'` | Append `'z'` | `"z"` |
| 1 | `'*'` | Remove last character | `""` |
| 2 | `'#'` | Duplicate result | `""` |

Final result: `""`

Since index `k = 0` is out of bounds, return `'.'`.

---

## Constraints

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters and the special characters `'*'`, `'#'`, and `'%'`.
- `0 <= k <= 10^15`
- The length of `result` after processing `s` will not exceed `10^15`.