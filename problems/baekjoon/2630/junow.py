from sys import stdin, setrecursionlimit

# setrecursionlimit(10000)


def check(sy, ey, sx, ex):
  color = board[sy][sx]
  for i in range(sy, ey+1):
    for j in range(sx, ex+1):
      if board[i][j] != color:
        return False
  return True


def dfs(sy, ey, sx, ex):
  if sy == ey or check(sy, ey, sx, ex):
    ans[board[sy][sx]] += 1
    return
  else:
    my = (sy+ey)//2
    mx = (sx+ex)//2
    dfs(sy, my, sx, mx)
    dfs(sy, my, mx+1, ex)
    dfs(my+1, ey, sx, mx)
    dfs(my+1, ey, mx+1, ex)


if __name__ == '__main__':
  ans = [0, 0]
  N = int(stdin.readline())
  board = []
  for _ in range(N):
    board.append(list(map(int, stdin.readline().split())))

  dfs(0, N-1, 0, N-1)

  print(ans[0])
  print(ans[1])
