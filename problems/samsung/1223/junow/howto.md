# 1223. 계산기2

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14nnAaAFACFAYD&categoryId=AV14nnAaAFACFAYD&categoryType=CODE)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   D4   |   87.52%    |

## 설계

- priority dictionary 에 +, \* 우선순위 기록 (\_ > +)
- 스택 구현
- 후위식으로 변환 [참조](https://jamanbbo.tistory.com/53)
  1. 피연산자는 스택에 넣지 않고 그냥 출력한다.
  2. 연산자는 스택이 비었으면 스택에 push한다.
  3. 연산자는 스택이 비어있지 않은경우
     1. 스택에 있는 연산자와의 우선순위를 비교해 스택에 있는 연산자의 우선순위가 같거나 크다면
     2. 스택에 있는 연산자를 pop을 한 후 출력하고 현재 연산자는 스택에 push한다.
     3. 3-1번으로 돌아감
  4. 만약 3번에서 우선순위가 현재 연산자가 더 크면 현재 연산자를 push한다.(스택에서 pop하지 않음)
  5. 수식이 끝나면 스택이 빌 때 까지 pop을 한 후 출력한다.
- 후위식 계산
  - 피연산자인경우
    - 스택에 push
  - 스택에서 두개 pop 해서 연산 후 스택에 push

### 시간복잡도

O(N) 보다는 클것같은데 잘 모르겠네요..

### 공간복잡도

### 자료구조

- Stack

## 고생한 점

- 마지막에 스택에 남은 연산자를 후위식에 넣어주는걸 깜빡해서 좀 해맸네요~
