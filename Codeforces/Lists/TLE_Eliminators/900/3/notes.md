n, k, and x, and he has to determine if he can choose k distinct integers between 1 and n, such that their sum is equal to x. answer is "YES" if he can, otherwise "NO".

1...n
select k distinct integers
sum = x
brute force: O(n^k) - too slow

## did it in first try
slightly optimal approach: find smallest and largest possible sums of k distinct integers
smallest sum = 1 + 2 + ... + k = k * (k + 1) / 2
largest sum = (n - k + 1) + (n - k + 2) + ... + n = k * (2n - k + 1) / 2
if smallest sum <= x <= largest sum, then answer is "YES", otherwise "NO"



n,n-1,n-2,...,n-k+1
largest_sum = k * (2 * n - k + 1) // 2