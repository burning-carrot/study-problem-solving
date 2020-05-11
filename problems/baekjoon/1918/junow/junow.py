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


priority = {}
priority['+'] = 1
priority['-'] = 1
priority['*'] = 2
priority['/'] = 2


def solution():
  infix = input()
  postfix = ''
  stack = Stack()

  for ch in infix:  
    if ch.isalpha():
      postfix += str(ch)
    elif ch == '(':
      stack.push(ch)
    elif ch == ')':
      while stack.peek() != '(':
        postfix += str(stack.pop())
      stack.pop()
    else:
      if stack.is_empty():
        stack.push(ch)
      else:
        while stack.is_empty() == False and stack.peek() != '(' and priority[stack.peek()] >= priority[ch]:
          postfix += stack.pop()
        stack.push(ch)

  while stack.is_empty() == False:
    postfix += stack.pop()

  print(postfix)






solution()



