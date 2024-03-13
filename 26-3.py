def good(i, j):
    return (i >= 0) and (j >= 0) and (i < n) and (j < m)
def solve(i, j):
    if good(i, j):
        if dp[i][j] == -1:
            t = solve(i - 2, j - 1) + solve(i - 2, j + 1)
            dp[i][j] = t + solve(i - 1, j - 2) + solve(i + 1, j - 2)
    else:
        return 0
    return dp[i][j]
n, m = map(int, input().split())
dp = []
for i in range(n):
    dp.append([-1] * m)
dp[0][0] = 1
print(solve(n - 1, m - 1))
