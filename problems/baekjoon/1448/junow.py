from sys import stdin

N = int(stdin.readline())
sticks = []
answer = -1

for _ in range(N):
  sticks.append(int(stdin.readline()))

sticks = sorted(sticks, reverse=True)
for i, stick in enumerate(sticks):
  if i==N-2: break
  a,b,c = sticks[i], sticks[i+1], sticks[i+2]
  if a < b+c:
    answer = a+b+c
    break

print(answer)
