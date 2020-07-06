#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, A, B, a[101][101];
bool visit[101];
queue<pii> q;

int bfs() {
  int ret = INT_MAX;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.first == B) {
      ret = min(ret, cur.second);
      continue;
    }

    for (int i = 1; i < N + 1; i++) {
      if (visit[i]) continue;
      if (!a[cur.first][i]) continue;
      visit[i] = true;
      q.push({i, cur.second + 1});
    }
  }

  if (ret == INT_MAX) {
    return -1;
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> A >> B >> M;
  int t1, t2;
  for (int i = 0; i < M; i++) {
    cin >> t1 >> t2;
    a[t1][t2] = 1;
    a[t2][t1] = 1;
    if (t1 == A || t2 == A) {
      q.push({A, 0});
    }
  }

  cout << bfs() << "\n";

  return 0;
}