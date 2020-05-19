from sys import stdin

N = int(stdin.readline())
nums = [0 for i in range(10001)]

for i in range(N):
  num = int(stdin.readline())
  nums[num] +=1

for i in range(10001):
  if nums[i] != 0:
    for j in range(nums[i]):
      print(i)
