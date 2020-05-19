from sys import stdin

N = int(stdin.readline())
card = sorted(map(int,stdin.readline().split()))

M = int(stdin.readline())
num = list(map(int,stdin.readline().split()))

dic = {}
index = 0

for m in sorted(num):
  cnt=0
  if m not in dic:
    while index < N:
      if m==card[index]:
        cnt +=1
        index +=1
      elif m > card[index]:
        index +=1
      else: break;
    dic[m] = cnt

answer =' '.join(str(dic[m]) for m in num)
print(answer)
