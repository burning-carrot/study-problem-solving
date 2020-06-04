from sys import stdin

N = int(stdin.readline())
T = [0]*N
P = [0]*N
dp = [0]*20

for i in range(N):
  T[i], P[i] = map(int, stdin.readline().split())


for i in range(N):
  dp[i + T[i]] = max(dp[i+T[i]], dp[i] + P[i])
  dp[i+1] = max(dp[i], dp[i+1])


print(dp[N])
