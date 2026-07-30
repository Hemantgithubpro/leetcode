class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        # since distinct letters, so no need to check for duplicates
        # first 8:1, next 8:2, next 8:3, next 8:4
        ans: int = 0
        for i in range(n):
            ans += i // 8 + 1
        return ans

def main():
    sol = Solution()
    # word = "abcdefghijklmnopqrstuvwxyz"
    word = "xycdefghij"
    print(sol.minimumPushes(word))
    
if __name__ == "__main__":
    main()