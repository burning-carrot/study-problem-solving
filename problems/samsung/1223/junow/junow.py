TEST_CASE = 10

priority = {}
priority['+'] = 1
priority['*'] = 2

class Stack:
  def __init__(self):
    self.items = []

  def push(self, item):
    self.items.append(item)
  
  def pop(self):
    return self.items.pop()
  
  def print_stack(self):
    print(self.items)
  
  def peek(self):
    return self.items[len(self.items) - 1]
  
  def is_empty(self):
    return self.items == []

  def size(self):
    return len(self.items)

def infixToPostfix(infix):
  stack = Stack()
  postfix=''
  for ch in infix:
    if(ch.isdigit()):
      postfix += ch
    else:
      if stack.is_empty():
        stack.push(ch)
      else:
        while stack.is_empty()==False and priority[stack.peek()] >= priority[ch] :
          postfix += stack.pop()
        stack.push(ch)
    
  while stack.is_empty() == False:
    postfix += stack.pop()
  return postfix

def calc(arg1, arg2, op):
  if(op == '+'):
    return int(arg1) + int(arg2)
  return int(arg1) * int(arg2)

def calcPostfix(postfix):
  stack = Stack()
  for ch in postfix:
    if ch in priority:
      arg2 = stack.pop()
      arg1 = stack.pop()
      stack.push(calc(arg1, arg2, ch))
    else:
      stack.push(int(ch))

  return stack.pop()

for tc in range(TEST_CASE):
  length = int(input())
  infix = input()
  stack = Stack()
  postfix=infixToPostfix(infix)
  answer = calcPostfix(postfix)
  print('#{0}'.format(tc+1), answer)
