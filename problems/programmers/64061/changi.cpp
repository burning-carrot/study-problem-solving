#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  stack<int> s;

  for (int move : moves) {
    int x = move - 1;
    int doll = 0;

    for (int h = 0; h < board.size(); h++) {
      if (board[h][x] != 0) {
        doll = board[h][x];
        board[h][x] = 0;
        break;
      }
    }

    if (doll != 0) {
      if (s.empty()) {
        s.push(doll);
      } else if (s.top() != doll) {
        s.push(doll);
      } else {
        s.pop();
        answer += 2;
      }
    }
  }

  return answer;
}

int main() {
  vector<vector<int>> board = {{0, 0, 0, 0, 0},
                               {0, 0, 1, 0, 3},
                               {0, 2, 5, 0, 1},
                               {4, 2, 4, 4, 2},
                               {3, 5, 1, 3, 1}};
  vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
  int s = solution(board, moves);

  cout << s << endl;

  return 0;
}