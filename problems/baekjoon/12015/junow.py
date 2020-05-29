from sys import stdin
from bisect import bisect_left

def lisNSquare(arr):
  N = len(arr)
  dp = [1]*N
  answer = 0
  for i in range(N):
    for j in range(i):
      if arr[i] > arr[j]:
        dp[i] = max(dp[i], dp[j] + 1)
    answer = max(answer, dp[i])

  return answer

def lisNlogN(arr):
  N = len(arr)
  dp = [0]*N
  length = 0

  for num in arr:
    i = bisect_left(dp, num, 0, length)
    if i<0:
      i = 0
    dp[i] = num
    if i == length:
      length += 1
  
  return length

N = int(stdin.readline())
A = list(map(int, stdin.readline().split(' ')))

# print(lisNSquare(A))
print(lisNlogN(A))
