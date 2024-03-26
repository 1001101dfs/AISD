from math import inf
 
n, a, b = map(int, input().split())
dp = [0] * 2 + [inf] * (n - 1)
for i in range(2, n + 1):
    dp[i] = min(max(dp[i - j] + a, dp[j] + b) for j in range(1, i))
print(dp[-1])
