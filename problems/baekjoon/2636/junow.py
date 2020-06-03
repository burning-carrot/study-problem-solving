from sys import stdin
from collections import deque

dy = [-1,0,1,0]
dx = [0,1,0,-1]

Y, X = map(int, stdin.readline().split())
board = [[0]*101]*101

for i in range(X):
  board[i] = list(map(int, stdin.readline().split()))

def bfs():
  t=0
  prev=0
  while True:
    q = deque()
    q.append((0,0))
    melt = []
    while q:
      y, x = q.popleft()

      for dir in range(4):
        ny = y + dy[dir]
        nx = x + dx[dir]

        if  0 <= ny < Y and 0 <= nx < X:
          if board[ny][nx] == 0:
            board[ny][nx] = -1
            q.append((ny,nx))
          if board[ny][nx] == 1:
            board[ny][nx] = -1
            melt.append((ny,nx))
      
    if len(melt) == 0:
      break
  
      
    t += 1
    prev = len(melt)

    for y in range(Y):
      for x in range(X):
        if board[y][x] == -1:
          board[y][x] = 0

  return t, prev

time, cnt = bfs()

print(time)
print(cnt)
