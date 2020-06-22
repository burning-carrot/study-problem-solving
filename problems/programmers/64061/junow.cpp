#include <iostream>
#include <vector>
using namespace std;

int getDoll(vector<vector<int>>& board, int c, int N) {
  for (int i = 0; i < N; i++) {
    if (board[i][c] > 0) {
      int ret = board[i][c];
      board[i][c] = 0;
      return ret;
    }
  }

  return -1;
}

bool checkBasket(vector<int>& basket) {
  int len = basket.size();
  if (basket[len - 1] == basket[len - 2]) {
    basket.pop_back();
    basket.pop_back();
    return true;
  }
  return false;
}

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int N = board[0].size();
  vector<int> basket;

  for (int move : moves) {
    int doll = getDoll(board, move - 1, N);
    if (doll > 0) {
      basket.push_back(doll);
    }
    if (checkBasket(basket)) {
      answer += 2;
    }
  }

  return answer;
}

int main(void) {
  vector<vector<int>> board({
      vector<int>({0, 0, 0, 0, 0}),
      vector<int>({0, 0, 1, 0, 3}),
      vector<int>({0, 2, 5, 0, 1}),
      vector<int>({4, 2, 4, 4, 2}),
      vector<int>({3, 5, 1, 3, 1}),
  });

  vector<int> moves({1, 5, 3, 5, 1, 2, 1, 4});
  cout << solution(board, moves) << "\n";
  return 0;
}
