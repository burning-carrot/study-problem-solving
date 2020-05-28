from sys import stdin

N = int(stdin.readline())
arr = [0]
for i in range(N):
  arr.append(int(stdin.readline()))

dp1 = [0, arr[1]]
dp2 = [0, arr[1]]

for i in range(2, N + 1):
  dp1.append(dp2[i-1] + arr[i])
  dp2.append(max(dp1[i-2], dp2[i-2]) + arr[i])

print(max(dp1[N], dp2[N]))
