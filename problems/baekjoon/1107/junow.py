from sys import stdin

def check(num, broken):
  numStr = str(num)
  for n in numStr:
    if int(n) in broken:
      return False
  return True

N = int(stdin.readline())
M = int(stdin.readline())
broken = set()
answer = abs(N-100)

broken = set(map(int, stdin.readline().split()))

for num in range(1000001):
  cur = str(num)
  if check(cur, broken):
    answer = min(answer, abs(num-N) + len(cur))


print(answer)
