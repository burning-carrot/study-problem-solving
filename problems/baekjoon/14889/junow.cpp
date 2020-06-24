#include <bits/stdc++.h>

using namespace std;

int n, board[20][20], ans;
int visit[20];

void dfs(int _i, int _cnt) {
  if (_i == n) return;
  if (_cnt == n / 2) {
    for (int i = 0; i < n; i++) {
      cout << visit[i] << " ";
    }
    cout << "\n";
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visit[i] == 1 && visit[j] == 1) {
          t1 += board[i][j];
        }
        if (visit[i] == 0 && visit[j] == 0) {
          t2 += board[i][j];
        }
      }
    }
    ans = min(ans, abs(t1 - t2));

    return;
  }

  dfs(_i + 1, _cnt);
  visit[_i] = 1;
  dfs(_i + 1, _cnt + 1);
  visit[_i] = 0;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  ans = 0x7f7f7f7f;

  dfs(0, 0);
  cout << ans << "\n";
  return 0;
}