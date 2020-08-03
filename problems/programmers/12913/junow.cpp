#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int R, ans;
int dp[100000][4];
void func(vector<vector<int>>& land) {
  for (int i = 1; i < R; i++) {
    dp[i][0] = land[i][0] + max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3]));
    dp[i][1] = land[i][1] + max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]));
    dp[i][2] = land[i][2] + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]));
    dp[i][3] = land[i][3] + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
  }
  ans = max(max(dp[R - 1][0], dp[R - 1][1]), max(dp[R - 1][2], dp[R - 1][3]));
}

int solution(vector<vector<int>> land) {
  R = land.size();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < 4; j++) {
      dp[i][j] = land[i][j];
    }
  }

  func(land);

  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> land = {
      {1, 2, 3, 5},
      {5, 6, 7, 8},
      {4, 3, 2, 1},
  };

  cout << solution(land) << endl;
  return 0;
}