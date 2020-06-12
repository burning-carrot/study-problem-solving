from sys import stdin

A, B, C = map(int, stdin.readline().split())


def sol(a, b, c):
  if b == 0:
    return 1
  else:
    t1 = sol(a, b//2, c) % c

    if b % 2 == 1:
      return (t1*t1*a) % c
    else:
      return (t1*t1) % c


print(sol(A, B, C))
