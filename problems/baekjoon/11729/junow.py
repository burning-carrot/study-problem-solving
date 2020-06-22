from sys import stdin

N = int(stdin.readline())
memo = {}


def hanoi(n, s, e):
  if (n, s, e) in memo:
    return memo[(n, s, e)]
  if n == 1:
    return '%d %d\n' % (s, e)

  r = s ^ e

  t1 = hanoi(n-1, s, r)
  memo[(n-1, s, r)] = t1
  t2 = '%d %d\n' % (s, e)
  t3 = hanoi(n-1, r, e)
  memo[(n-1, r, e)] = t3

  return t1 + t2 + t3


ans = hanoi(N, 1, 3)


print(2**N-1)
print(ans)
