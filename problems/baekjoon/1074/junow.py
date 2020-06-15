from sys import stdin

N, R, C = map(int, stdin.readline().split())


def dfs(n, r, c, cnt):
  if n == 0:
    return cnt

  m = pow(2, n)/2
  if r < m and c < m:
    # 2사분면
    return dfs(n-1, r, c, cnt)
  elif r < m and c >= m:
    # 1사분면
    return dfs(n-1, r, c-pow(2, n-1), cnt + pow(2, 2*n-2) * 1)
  elif r >= m and c < m:
    # 3사분면
    return dfs(n-1, r-pow(2, n-1), c, cnt + pow(2, 2*n-2) * 2)
  else:
    # 4사분면
    return dfs(n-1, r-pow(2, n-1), c-pow(2, n-1), cnt + pow(2, 2*n-2) * 3)


print(dfs(N, R, C, 0))
