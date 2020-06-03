from sys import stdin
import copy

N = int(stdin.readline())
ans = 0


def isCross(r, row):
  for i in range(len(row)):
    if abs(len(row)-i) == abs(r-row[i]):
      return False

  return True


def dfs(row):
  c = len(row)
  if c == N:
    global ans
    ans += 1
    return
  for r in range(N):
    if r in row:
      continue

    if isCross(r, row) != True:
      continue

    newRow = row[:]
    newRow.append(r)

    dfs(newRow)


if N == 0:
  print(0)
else:
  row = [0]*N
  dfs([])
  print(ans)
