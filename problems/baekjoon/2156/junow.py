from sys import stdin

def sol(N, arr):
  dp = [0] * N

  dp[0] = arr[0]
  if N == 1:
    return dp[0]

  dp[1] = arr[0] + arr[1]
  if N == 2:
    return dp[1]
  
  for i in range(2, N):
    dp[i] = max(
      dp[i-1],
      dp[i-2] + arr[i],
      dp[i-3] + arr[i-1] + arr[i],
    )
  
  return dp[N-1]

N = int(stdin.readline())
dp = [0]*N
arr = []
for _ in range(N):
  arr.append(int(stdin.readline()))

print(sol(N, arr))
