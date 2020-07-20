#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

char board[5][5];
bool visit[5][5];
int perm[5][5];

bool isInRange(int x, int y) {
  return min(x, y) >= 0 && max(x, y) < 5;
}

int dfs(int x, int y) {
  visit[x][y] = true;
  int ret = 1;
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!isInRange(ny, nx)) continue;  // 범위안에 있는지
    if (visit[nx][ny]) continue;       // 이미 방문했는지
    if (!perm[nx][ny]) continue;       // 해당 지점 갈 수 있는지

    ret += dfs(nx, ny);
  }
  return ret;  // 방문한 지점 리턴;
}

void input() {
  for (int i = 0; i < 5; i++) {
    cin >> board[i];
  }
}

int solve() {
  int ans = 0;
  vi selected(25, 0);
  for (int i = 0; i < 7; i++) {
    selected[24 - i] = 1;
  }

  do {
    fill(&perm[0][0], &perm[4][4], 0);
    int y_cnt = 0;
    int sx, sy;
    for (int i = 0; i < 25; i++) {
      int x = i / 5;
      int y = i % 5;
      perm[x][y] = selected[i];
      if (selected[i]) {
        sx = x;
        sy = y;
        y_cnt += board[x][y] == 'Y';
      }
    }
    if (y_cnt >= 4) continue;
    fill(&visit[0][0], &visit[4][4], 0);
    ans += dfs(sx, sy) == 7;
  } while (next_permutation(selected.begin(), selected.end()));

  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  input();

  cout << solve() << endl;
  return 0;
}