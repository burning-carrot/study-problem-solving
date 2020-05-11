# 1224. 계산기3

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14tDX6AFgCFAYD)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   D4   |    90.91    |

## 설계

[백준 1918](../../../baekjoon/1918/junow/junow.py) 와 전체적인 맥락은 같음

피연산자가 알파벳이 아닌 숫자라는 차이가 있음.
후위식을 계산하는 함수는 [samsung 1223](../../1223/junow/junow.py#L52) 와 같음

### 시간복잡도

후위식 변환 - O(N)
후위식 계산 - O(N)

후위식 변환 과정에 for 와 while 이 중첩되어 있지만 for 는 최대 N 만큼 while 은 그 안에서 최대 N/2 만큼??

그러면 O(N^2) 인지??

[찾아보니](http://dblab.duksung.ac.kr/ds/pdf/Chap05.pdf)

시간 - O(r)

- r: 수식의 기호의 개수

공간 - S(n) = n

- n: 연산자의 수 라네요

### 공간복잡도

isp - O(1)
icp - O(1)
stack (infix -> postfix) - O(N)
stack (calculate postfix) - O(N)

### 자료구조

stack

## 고생한 점
