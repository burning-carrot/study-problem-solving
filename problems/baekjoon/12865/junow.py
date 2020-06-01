from sys import stdin

def knapSack(W, wt, val, n):
  dp = [[0 for x in range(W+1)] for x in range(n+1)]
  for i in range(n+1):
    for w in range(W + 1):
      if i == 0 or w == 0:
        dp[i][w] = 0
      elif wt[i-1] <= w:
        dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
      else:
        dp[i][w] = dp[i-1][w]

  return dp[n][W]


[N, K] = list(map(int, stdin.readline().split(' ')))
w = [0 for _ in range(N)]
v = [0 for _ in range(N)]
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(N):
  [w[i], v[i]] = list(map(int, stdin.readline().split(' ')))

answer = knapSack(K, w, v, N)

print(answer)