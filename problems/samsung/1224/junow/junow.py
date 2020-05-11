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

TEST_CASE=10
isp = {
  '+': 1,
  '-': 1,
  '*': 2,
  '/': 2,
  '(': 0
}
icp = {
  '+': 1,
  '-': 1,
  '*': 2,
  '/': 2,
  '(': 3
}

def calc(arg1, arg2, op):
  if(op == '+'):
    return int(arg1) + int(arg2)
  return int(arg1) * int(arg2)

def calcPostfix(postfix):
  stack = Stack()
  for ch in postfix:
    if ch in isp:
      arg2 = stack.pop()
      arg1 = stack.pop()
      stack.push(calc(arg1, arg2, ch))
    else:
      stack.push(int(ch))

  return stack.pop()

def infixToPosifix(infix):
  postfix = ''
  stack = Stack()

  for ch in infix:  
    if ch.isnumeric():
      postfix += str(ch)
    elif ch == ')':
      while stack.peek() != '(':
        postfix += str(stack.pop())
      stack.pop()
    else:
      if stack.is_empty():
        stack.push(ch)
      else:
        while stack.is_empty() == False and isp[stack.peek()] >= icp[ch]:
          if stack.peek() == '(':
            stack.pop()
            break
          else:
            postfix += stack.pop()
        stack.push(ch)

  while stack.is_empty() == False:
    postfix += stack.pop()

  return postfix

def solution():
  length = input()
  infix = input()
  postfix = infixToPosifix(infix)
  answer = calcPostfix(postfix)

  print('#{0}'.format(tc+1), answer)



for tc in range(TEST_CASE):
  solution()
