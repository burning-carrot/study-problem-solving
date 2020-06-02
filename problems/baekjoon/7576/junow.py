from sys import stdin
from collections import deque

dy = [-1,0,1,0]
dx = [0,1,0,-1]

MAX=1000
M, N = map(int, stdin.readline().split())
q = deque()

board = [list(map(int, stdin.readline().split())) for _ in range(N)]
  
for i in range(N):
  for j in range(M):
    if board[i][j] == 1:
      q.append((i,j))

def bfs():
  ret=0

  while(q):
    y, x = q.popleft()

    for dir in range(4):
      ny = y + dy[dir]
      nx = x + dx[dir]

      if ny < 0 or nx < 0 or ny >= N or nx >= M: continue
      if board[ny][nx] != 0: continue

      board[ny][nx] = board[y][x] + 1
      q.append((ny, nx))


  for i in range(N):
    if 0 in board[i]:
      return -1;
    ret = max(ret, max(board[i]))

  return ret-1;

print(bfs())