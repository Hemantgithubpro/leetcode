class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        v = [True] * (n + 1)
        i = 2
        while i * i <= n:
            if v[i]:
                for j in range(i * i, n + 1, i):
                    v[j] = False
            i += 1
        
        ans = 0
        for i in range(2, n):
            if v[i]:
                ans += 1
        return ans

if __name__ == "__main__":
    print(Solution().countPrimes(10))
