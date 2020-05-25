from sys import stdin

N = int(stdin.readline())
nums = [0 for i in range(10001)]

for i in range(N):
  num = int(stdin.readline())
  nums[num] +=1

for i, cnt in enumerate(nums):
  if cnt > 0:
    print((cnt)*'{}\n'.format(i), end='')
    