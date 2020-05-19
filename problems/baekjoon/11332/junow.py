from math import log2
from sys import stdin

MAX = 100000000
CORRECT = 'May Pass.'
WRONG = 'TLE!'

TEST_CASE  = int(stdin.readline())

def fac(T, N, L):
  ret = 1
  for i in range(N):
    ret *= (i+1)
    if(ret >= MAX*L/T):
      return False
  return ret

def On(T, N, L):
  return N*T <= MAX*L

def NSquare(T, N, L):
  return T*(N**2) <= MAX*L

def NCube(T, N, L): 
  return T*(N**3) <= MAX*L

def expo2(T, N, L):
  return log2(T)+N <= log2(MAX*L)

def NFac(T, N, L):
  return fac(T, N, L)

dict = {
  'O(N)': On,
  'O(N^2)': NSquare,
  'O(N^3)': NCube,
  'O(2^N)': expo2,
  'O(N!)': NFac,
}

for tc in range(TEST_CASE):
  S, N, T, L = stdin.readline()[:-1].split()
  N = int(N)
  T = int(T)
  L = int(L)

  if dict[S](T,N,L):
    print(CORRECT)
  else:
    print(WRONG)

