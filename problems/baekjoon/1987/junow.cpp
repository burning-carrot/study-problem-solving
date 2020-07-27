#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int r, c, ans, visit;
char board[20][20];

bool isInRange(int y, int x) {
  return min(y, x) >= 0 && y < r && x < c;
}

void bt(int y, int x, int depth) {
  ans = max(ans, depth);

  for (int dir = 0; dir < 4; dir++) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (!isInRange(ny, nx)) continue;
    int next = board[ny][nx] - 64;
    if (visit & (1 << next)) continue;

    visit |= (1 << next);
    bt(ny, nx, depth + 1);
    visit &= ~(1 << next);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> board[i];
  }
  visit |= 1 << (board[0][0] - 64);
  bt(0, 0, 0);

  cout << ans + 1 << endl;

  return 0;
}