# 1222. 계산기1

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14mbSaAEwCFAYD)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|   D4   |   86.71%    |

## 설계

굳이 스택을 쓰지 않아도 되는 문제 같아서 숫자들 다 더해서 출력했습니다.

### 시간복잡도

- O(N)

### 공간복잡도

- O(N)

### 자료구조

## 고생한 점

삼성에서 sys 모듈 import 가 금지되어 있어서 input() 으로 입력받는거 처음 해봤습니다.
stdin.readline() 과는 다르게 끝에 개행문자가 들어오지 않아서 [:-1] 이 필요없게 되었습니다.
