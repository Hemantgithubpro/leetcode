from collections import Counter


class Solution:

    def minimumPushes(self, word: str) -> int:
        # 1. Count frequency of each character
        freq_map = Counter(word)

        # 2. Sort frequencies in descending order
        sorted_frequencies = sorted(freq_map.values(), reverse=True)

        # 3. Calculate total pushes based on sorted frequencies
        ans = 0
        for i, count in enumerate(sorted_frequencies):
            pushes_per_press = i // 8 + 1
            ans += count * pushes_per_press

        return ans

def main():
    sol = Solution()
    
    word:str = "aabbccddeeffgghhiiiiii"
    result = sol.minimumPushes(word)
    # print(f"Minimum pushes for '{word}': {result}")
    print(f"{result}")


if __name__ == "__main__":
    main()