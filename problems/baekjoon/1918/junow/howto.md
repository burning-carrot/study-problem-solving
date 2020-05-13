# 1918. 후위 표기식

[링크](https://www.acmicpc.net/problem/1918)

[괄호 없는 버전](../../../samsung/1223/junow/howto.md) 과 비슷

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   30.905%   |

## 설계

- 수도코드

```pseudocode
stack <- []
postfix <- ''
priority[+] <- 1
priority[-] <- 1
priority[*] <- 2
priority[/] <- 2

for ch in infix
  if ch is operand
    postfix <- ch
  if ch is '('
    stack <- ch
  if ch is ')'
    while stack not empty and stack top is not '('
      postfix <- stack.pop
    stack.pop
  if ch is operator
    if stack is empty
      stack <- ch
    else:
      while stack not empty and stack top is not '(' and priority[stack.top] >=  priority[ch]
        postfix <- stack.pop
      stack <- ch

while stack is not empty
  postfix <- stack.pop

return postfix


```

### 시간복잡도

- 그냥 한바퀴 돌앗으니 O(N)???..

### 공간복잡도

- infix - O(N)
- postfix - O(N)
- stack - O(N)
- priority - O(1) (상수니까 1??)

### 자료구조

- stack

## 고생한 점

- 스택을 잘못 구현했는지 stack.pop(), stack.peek() 할때마다 비었는지 체크해야되서 여러번 멈칫멈칫 했네요 코드도 상당히 더러워졌어요
