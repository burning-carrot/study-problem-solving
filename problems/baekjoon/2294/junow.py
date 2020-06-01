from sys import stdin

[N, K]= map(int, stdin.readline().split(' '))
arr = [0]*10001
dp = [10001]*10001

for i in range(N):
  arr[i] = (int(stdin.readline()))

dp[0] = 0
for i in range(1,K+1):
  for j in range(N):
    if i-arr[j] >= 0:
      dp[i] = min(dp[i-arr[j]] + 1, dp[i])

if dp[K] == 10001:
  print(-1)
else:
  print(dp[K])

