from sys import stdin

TEST_CASE = int(stdin.readline())
cnt0 = [0]*41
cnt1 = [0]*41
cnt0[0] = 1
cnt1[1] = 1

for tc in range(TEST_CASE):
  N = int(stdin.readline())
  for i in range(2, N+1):
    cnt0[i] = cnt0[i-1] + cnt0[i-2]
    cnt1[i] = cnt1[i-1] + cnt1[i-2]

  print(cnt0[N], cnt1[N])