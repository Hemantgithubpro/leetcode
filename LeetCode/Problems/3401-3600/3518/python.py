class Solution:
    # Safely calculates permutations capped at cap
    def count_permutations(self, freq: list[int], cap: int) -> int:
        ans = 1
        total = 0

        for f in freq:
            if f == 0:
                continue
            if total == 0:
                total += f
                continue

            # Calculate combinations dynamically: C(total + f, f)
            limit = min(f, total)
            n = total + f

            for i in range(1, limit + 1):
                ans = ans * (n - i + 1) // i

                # Break early if we exceed our capacity requirement
                if ans > cap:
                    return cap + 1
            total += f

        return ans
    def smallestPalindrome(self, s: str, k: int) -> str:
        # Step 1: Count character frequencies
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord('a')] += 1

        half_freq = [0] * 26
        odd_count = 0
        mid_char = ""

        # Step 2: Extract half-frequencies for the first half of the palindrome
        for i in range(26):
            half_freq[i] = freq[i] // 2
            if freq[i] % 2 != 0:
                odd_count += 1
                mid_char = chr(ord('a') + i)

        # Step 3: Check if k is within the total possible distinct permutations
        total_perms = self.count_permutations(half_freq, k)
        if total_perms < k:
            return ""

        first_half = []
        m = len(s) // 2

        # Step 4: Lexicographically build the first half
        for pos in range(m):
            for ch in range(26):
                if half_freq[ch] == 0:
                    continue

                half_freq[ch] -= 1
                cnt = self.count_permutations(half_freq, k)

                if k > cnt:
                    k -= cnt
                    half_freq[ch] += 1  # Revert and try the next letter
                else:
                    first_half.append(chr(ord('a') + ch))
                    break  # Lock in the character

        # Step 5: Assemble the final palindrome (First Half + Middle + Reversed First Half)
        half_str = "".join(first_half)
        return half_str + mid_char + half_str[::-1]

    
    
def main():
    solution = Solution()
    print(solution.smallestPalindrome("aabaa", 2))  # Expected: "aba"
    print(solution.smallestPalindrome("abccba", 3))  # Expected: "abc"
    print("hello")

if __name__ == "__main__":
    main()