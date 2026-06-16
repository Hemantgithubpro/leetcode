**Process string with special operations 1**

You are given a string s consisting of lowercase English letters and the special characters `*`, `#`, and `%`.

Process the string from left to right to build a new string `result` using these rules:

- If the character is a lowercase English letter, append it to `result`.
- `*` : remove the last character from `result` if it exists.
- `#` : duplicate the current `result` and append it to itself (i.e., `result = result + result`).
- `%` : reverse the current `result`.

Return the final string `result` after processing all characters in `s`.

**Example 1**

Input:

```
s = "a#b%*"
```

Output:

```
"ba"
```

Step-by-step:

| i | s[i] | Operation | Current result |
|---:|:----:|:----------|:---------------|
| 0 | 'a'  | Append 'a' | "a" |
| 1 | '#'  | Duplicate result | "aa" |
| 2 | 'b'  | Append 'b' | "aab" |
| 3 | '%'  | Reverse result | "baa" |
| 4 | '*'  | Remove last character | "ba" |

Final result: `"ba"`.

**Example 2**

Input:

```
s = "z*#"
```

Output:

```
""
```

Step-by-step:

| i | s[i] | Operation | Current result |
|---:|:----:|:----------|:---------------|
| 0 | 'z'  | Append 'z' | "z" |
| 1 | '*'  | Remove last character | "" |
| 2 | '#'  | Duplicate result | "" |

Final result: an empty string `""`.

**Constraints**

- 1 <= s.length <= 20
- `s` contains only lowercase English letters and the characters `*`, `#`, and `%`.

**Notes**

- Operations apply to the current `result` at the time they are processed (left to right).
- Duplicating or reversing an empty string keeps it empty.