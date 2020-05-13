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
def solution():
  infix = input()
  postfix = ''
  stack = Stack()

  for ch in infix:  
    if ch.isalpha():
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


  print(postfix)


solution()
