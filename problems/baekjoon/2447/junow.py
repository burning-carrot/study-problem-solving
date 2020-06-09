from sys import stdin


def printStar(board, N):
  for b in board:
    print(''.join(b))


def white(board, y, x):
  for i in range(y, y+3):
    for j in range(x, x+3):
      board[i][j] = ' '


def star(board, y, x):
  for i in range(y, y+3):
    for j in range(x, x+3):
      if i == y+1 and j == x+1:
        board[i][j] = ' '
        continue
      board[i][j] = '*'


def dfs(board, n, y, x):
  nN = n//3
  if n == 3:
    star(board, y, x)
    return
  for i in range(y, y+n, nN):
    for j in range(x, x+n, nN):
      if i == y+nN and j == x+nN:
        continue

      dfs(board, nN, i, j)
  return


if __name__ == '__main__':
  N = int(stdin.readline())
  board = [[' ' for _ in range(N)] for _ in range(N)]
  dfs(board, N, 0, 0)
  printStar(board, N)
