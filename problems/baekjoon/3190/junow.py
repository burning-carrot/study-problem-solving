from sys import stdin
from collections import deque
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
d = 1
N = int(stdin.readline())
K = int(stdin.readline())
apples = set()
moves = {}
snake = deque()
snake.append([0, 0])

for _ in range(K):
  i, j = map(int, stdin.readline().split())
  apples.add((i-1, j-1))

L = int(stdin.readline())

for _ in range(L):
  X, C = stdin.readline().split()
  moves[int(X)] = C

sec = 0
while True:
  # printSnake(sec)
  if sec in moves.keys():
    nd = moves[sec]
    del moves[sec]
    if nd == 'D':
      d += 1
    else:
      d += 3
    d %= 4

  head = snake[len(snake)-1]
  ny = head[0] + dy[d]
  nx = head[1] + dx[d]

  if ny < 0 or ny >= N or nx < 0 or nx >= N:
    break
  # 자기자신
  if [ny, nx] in snake:
    break

  if (ny, nx) in apples:
    apples.remove((ny, nx))
    snake.append([ny, nx])
  else:
    snake.append([ny, nx])
    snake.popleft()

  sec += 1


print(sec+1)
