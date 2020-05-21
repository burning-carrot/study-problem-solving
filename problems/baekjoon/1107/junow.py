from sys import stdin

def check(num, broken):
  numStr = str(num)
  for n in numStr:
    if int(n) in broken:
      return False
  return True

def bf(N, broken):
  minClick=1000001
  for num in range(1000001):
    if check(num, broken):
      minClick = min(minClick, abs(N-num) + len(str(N)))

  return minClick

N = int(stdin.readline())
M = int(stdin.readline())
broken = set()
answer = abs(N-100)
if M>0:
  broken = set(map(int, stdin.readline().split()))
  answer = min(answer, bf(N, broken))
  print(answer)
else:
  answer = min(abs(len(str(N))), abs(100-N))
  print(answer)
