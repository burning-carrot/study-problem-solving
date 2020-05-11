from sys import stdin

def calc(arg1, arg2, op):
  if op=='+':
    return arg1 + arg2
  elif op == '-':
    return arg1 - arg2
  elif op == '*':
    return arg1*arg2
  else:
    return arg1/arg2

n = int(stdin.readline())
expression = stdin.readline()[:-1]

stack = list()

dict = {}
for i in range(n):
  dict[chr(ord('A') + i)] = int(stdin.readline())

for ch in expression:
  if ch in dict:
    stack.append(dict[ch])
  else:
    arg2 = stack.pop()
    arg1 = stack.pop()
    result = calc(arg1, arg2, ch)
    stack.append(result)
    

print(format(stack[0], ".2f"))
